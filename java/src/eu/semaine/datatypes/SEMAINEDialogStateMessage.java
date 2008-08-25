/**
 * Copyright (C) 2008 DFKI GmbH. All rights reserved.
 * Use is subject to license terms -- see license.txt.
 */
package eu.semaine.datatypes;

import java.util.Collections;
import java.util.SortedSet;
import java.util.TreeSet;

import javax.jms.Message;

import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import eu.semaine.exceptions.MessageFormatException;
import eu.semaine.util.XMLTool;

/**
 * @author marc
 *
 */
public class SEMAINEDialogStateMessage extends SEMAINEStateMessage
{
	public static final String APIVersion = "0.1";

	private SortedSet<DialogAct> dialogHistory = new TreeSet<DialogAct>();
	/**
	 * @param message
	 * @param whatState
	 * @param apiVersion
	 * @throws MessageFormatException
	 */
	public SEMAINEDialogStateMessage(Message message)
	throws MessageFormatException
	{
		super(message, "DialogState", APIVersion);
	}

	
	/**
	 * Set up the possible values that we can know about.
	 * Things that are not previewed here will not be read from the document.
	 * When this changes, the APIVersion must change with it.
	 */
	protected void setupInfoKeys()
	{
		info.put("speaker", null);
		info.put("listener", null);
		info.put("topic", null);
	}

	protected boolean analyseElement(Element el)
	throws MessageFormatException
	{
		// We do not user super implementation here, because
		// dialog state does not use emotionml:category.
		
		String namespace = el.getNamespaceURI();
		String tagname = el.getTagName();
		if (namespace.equals(SemaineML.namespace)) {
			if (tagname.equals(SemaineML.SPEAKER)) {
				String value = XMLTool.needAttribute(el, SemaineML.WHO);
				info.put("speaker", value);
				return true;
			} else if (tagname.equals(SemaineML.LISTENER)) {
				String value = XMLTool.needAttribute(el, SemaineML.WHO);
				info.put("listener", value);
				return true;
			} else if (tagname.equals(SemaineML.TOPIC)) {
				String value = XMLTool.needAttribute(el, SemaineML.NAME);
				info.put("topic", value);
				return true;
			} else if (tagname.equals(SemaineML.DIALOG_HISTORY)) {
				NodeList nodes = el.getChildNodes();
				for (int i=0, max=nodes.getLength(); i<max; i++) {
					Node n = nodes.item(i);
					if (!(n.getNodeType() == Node.ELEMENT_NODE)) {
						continue;
					}
					assert n instanceof Element : "Should only see elements here";
					Element child = (Element) n;
					if (!(child.getNamespaceURI().equals(SemaineML.namespace)
						  && child.getTagName().equals(SemaineML.DIALOG_ACT))) {
						throw new MessageFormatException("Element '"+SemaineML.DIALOG_HISTORY+
								"' in namespace '"+el.getNamespaceURI()+
								"' should only contain child elements named '"+SemaineML.DIALOG_ACT+
								"' in the same namespace");
					}
					String text = child.getTextContent();
					String speaker = XMLTool.needAttribute(child, SemaineML.WHO);
					String topic = XMLTool.needAttribute(child, SemaineML.TOPIC);
					String timeString = XMLTool.needAttribute(child, SemaineML.TIME);
					long time = 0;
					try {
						time = Long.valueOf(timeString);
					} catch (NumberFormatException nfe) {
						throw new MessageFormatException("Cannot parse time '"+timeString+"' as long", nfe);
					}
					DialogAct da = new DialogAct(text, speaker, topic, time);
					dialogHistory.add(da);
				}
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Get read-only access to the dialog history. The iterator of the sorted
	 * set will return the dialog acts sorted by time, most recent first.
	 * @return a set of dialog acts, or null if the message doesn't contain a dialog history.
	 */
	public SortedSet<DialogAct> getDialogHistory()
	{
		return Collections.unmodifiableSortedSet(dialogHistory);
	}

	public static class DialogAct implements Comparable<DialogAct>
	{
		private String text;
		private String speaker;
		private String topic;
		private long time;
		
		public DialogAct(String text, String speaker, String topic, long time)
		{
			this.text = text;
			this.speaker = speaker;
			this.topic = topic;
			this.time = time;
		}
		
		/**
		 * Method used for sorting Dialog acts by their time, newest first.
		 */
		public int compareTo(DialogAct other)
		{
			if (time == other.time) return 0;
			if (time < other.time) return 1;
			return -1;
		}
		
		public String getText()
		{
			return text;
		}
		
		public String getSpeaker()
		{
			return speaker;
		}
		
		public String getTopic()
		{
			return topic;
		}
		
		public long getTime()
		{
			return time;
		}
	}
}

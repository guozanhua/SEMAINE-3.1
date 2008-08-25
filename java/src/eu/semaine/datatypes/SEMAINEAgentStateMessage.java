/**
 * Copyright (C) 2008 DFKI GmbH. All rights reserved.
 * Use is subject to license terms -- see license.txt.
 */
package eu.semaine.datatypes;

import javax.jms.Message;

import org.w3c.dom.Element;

import eu.semaine.exceptions.MessageFormatException;
import eu.semaine.util.XMLTool;

/**
 * @author marc
 *
 */
public class SEMAINEAgentStateMessage extends SEMAINEStateMessage
{
	public static final String APIVersion = "0.1";

	/**
	 * @param message
	 * @param whatState
	 * @param apiVersion
	 * @throws MessageFormatException
	 */
	public SEMAINEAgentStateMessage(Message message)
	throws MessageFormatException
	{
		super(message, "AgentState", APIVersion);
	}

	
	/**
	 * Set up the possible values that we can know about.
	 * Things that are not previewed here will not be read from the document.
	 * When this changes, the APIVersion must change with it.
	 */
	protected void setupInfoKeys()
	{
		info.put("emotion-quadrant", null);
		info.put("interest", null);
		info.put("stance to user", null);
		info.put("stance to topic", null);
		info.put("emotionally-concordant-with-user", null);
	}

	protected boolean analyseElement(Element el)
	throws MessageFormatException
	{
		// Give the super implementation the first try:
		if (super.analyseElement(el)) return true;
		
		String namespace = el.getNamespaceURI();
		String tagname = el.getTagName();
		if (namespace.equals(EmotionML.namespace)) {
			if (tagname.equals(EmotionML.EMOTION)) {
				String type = el.getAttribute(EmotionML.TYPE);
				if (type.equals("stance")) {
					Element object = XMLTool.needChildElementByTagNameNS(el, EmotionML.OBJECT, EmotionML.namespace);
					String objectName = object.getAttribute(EmotionML.NAME);
					String infoKey = "stance to "+objectName;
					if (!info.containsKey(infoKey)) {
						throw new MessageFormatException("unknown object '"+objectName+"'");
					}
					Element category = XMLTool.needChildElementByTagNameNS(el, EmotionML.CATEGORY, EmotionML.namespace);
					String set = XMLTool.needAttribute(category, EmotionML.SET);
					if (!set.equals("like-dislike")) {
						throw new MessageFormatException("a stance needs a category with set 'like-dislike'");
					}
					String value = XMLTool.needAttribute(category, EmotionML.NAME);
					// And finally...
					info.put(infoKey, value);
					return true;
				}
			}
		} else if (namespace.equals(SemaineML.namespace)) {
			if (tagname.equals(SemaineML.EMOTIONALLY_CONCORDANT_WITH_USER)) {
				String value = XMLTool.needAttribute(el, SemaineML.VALUE);
				info.put("emotionally-concordant-with-user", value);
				return true;
			}
		}
		return false;
	}
}

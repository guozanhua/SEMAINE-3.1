var timerID;
var isLiveUpdatingNow = false;
}
		CloseList(wb);
	ShowListNotUpdating(wb);
		if (wbAutoUpdateList[wb].length > 0) {
			c = GetInputValue(wb + "_ContinuousUpdateMax");
			// alert(wb + ": " + c);
			if ( (c < 1) || (c > 200) )
				c = 20;
			retrieveWBList(wb, c, CallbackWBList, wb);
		}
	}
}
		return;
    var html = "<table width=\"100%\"><tr><td align=\"center\" valign=\"middle\" class=\"keyConcept\">Updating list ... </td></tr></table>";
	if ( (c < 1) || (c > 200) )
		c = 20;
	retrieveWBList(wb, c, CallbackWBList, wb);
	var wb = "";
	
	try {
			p2 = req.responseText.indexOf(" -->");
			// alert(wb + "," + myajax.responseText);
			if ( (p1 >= 0) && (p2 > 0) ) {
				wb = req.responseText.substring(p1+5, p2);
				// alert(wb + "," + req.responseText);
			    UpdateWBList(wb, req.responseText);

function CallbackLiveUpdate(req) {
	var comp = "";

	try {
			var col_array = req.responseText.split("\n");
			var part_num=0;
			while (part_num < col_array.length)
			{
				if (col_array[part_num].length > 0) {
					// alert(col_array[part_num]);
					str = "changeText(" + col_array[part_num] + ");";
					// alert(str);
					eval(str);
				}
				part_num+=1;
			}
		}

function CallbackID(req) {
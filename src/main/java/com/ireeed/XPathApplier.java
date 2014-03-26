package com.ireeed;


public class XPathApplier {
	static {
		System.loadLibrary("htmlxpath");
	}

	public native String[] htmlEvalXPath(String page, String xpath);

	public native String[][] htmlEvalXPaths(String page, String[] xpaths);

	public native String[][] xmlEvalXPaths(String page, String[] xpaths);

}

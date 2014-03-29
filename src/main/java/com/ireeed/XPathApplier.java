package com.ireeed;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public class XPathApplier {
	static {
		System.loadLibrary("htmlxpath");
	}

	public native String[] htmlEvalXPath(String page, String xpath);

	public native String[][] htmlEvalXPaths(String page, String[] xpaths);

	public native String[][] xmlEvalXPaths(String page, String[] xpaths);
	
	
	public static class TreeBin{
		public List<Integer> index;
		public List<String> xpaths;
		
		public TreeBin(){
			this.index = new LinkedList<Integer>();
			this.xpaths = new LinkedList<String>();
		}
	}
	
	public static class XPathNode{
		public String xpath;
		public List<XPathApplier.XPathNode> children;
		public XPathApplier.XPathNode parent;
		public int serializeIndex;
		
		public XPathApplier.TreeBin serialize(){
			List<XPathApplier.XPathNode> ret = new LinkedList<XPathApplier.XPathNode>();
			
			List<XPathApplier.XPathNode> queue = new LinkedList<XPathApplier.XPathNode>();
			XPathApplier.TreeBin result = new TreeBin();
			
			queue.add(this);
			while(queue.size() > 0){
				XPathApplier.XPathNode node = queue.remove(0);
				
				int mask = 0xffff;
				int index = ret.size() & mask;
				
				mask = mask << 16;
				int offset = ((node.children == null?0:node.children.size()) << 16) & mask;
				
				index = index | offset;
				result.index.add(index);
				result.xpaths.add(node.xpath);
				
				node.serializeIndex = ret.size();
				ret.add(node);
				
				
				if(node.children != null){
					queue.addAll(node.children);
				}
			}
			
			
			return result;
		}
	}

}

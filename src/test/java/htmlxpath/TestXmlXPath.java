package htmlxpath;
import java.io.IOException;

import org.junit.Test;

import com.ireeed.XPathApplier;

import utils.HTML_Downloader;


public class TestXmlXPath {
	@Test
	public void testLastNameRewrite() throws IOException{
		String page = HTML_Downloader.download("http://www.businessinsider.com/thehive.rss");
		String[] xpaths = new String[]{
				"//item/title",
				"//item/pubDate"
		};
		
		String[][] result = new XPathApplier().xmlEvalXPaths(page, xpaths);
		
		for (int index = 0; index < result.length; index++) {
			String[] field = result[index];
			System.out.println(xpaths[index] + ":");
			for (int i = 0; i < field.length; i++) {
				System.out.println("\t" + field[i]);
			}
		}
	}
}

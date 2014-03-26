package htmlxpath;

import java.io.IOException;

import org.junit.Test;

import utils.HTML_Downloader;

import com.ireeed.XPathApplier;

public class TestHtmlXPath {

	@Test
	public void testLastNameRewrite() throws IOException{
		String page = HTML_Downloader.download("http://gma.yahoo.com/blogs/abc-blogs/woman-phantom-pregnancy-quintuplets-021913478--abc-news-health.html");
		String[] xpaths = new String[]{
				"//div[@id='mediabloghead']/div/h1",
				"//cite[@class='byline vcard']/span[@class='fn']/a/text()"
		};
		
		String[][] result = new XPathApplier().htmlEvalXPaths(page, xpaths);
		
		for (int index = 0; index < result.length; index++) {
			String[] field = result[index];
			System.out.println(xpaths[index] + ":");
			for (int i = 0; i < field.length; i++) {
				System.out.println("\t" + field[i]);
			}
		}
	}
}

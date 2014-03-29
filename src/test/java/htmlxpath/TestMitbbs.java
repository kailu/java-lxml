package htmlxpath;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;

import org.junit.Test;

import utils.HTML_Downloader;

import com.ireeed.XPathApplier;

public class TestMitbbs {
	@Test
	public void testLastNameRewrite() throws IOException{
		//FileOutputStream fs = new FileOutputStream(new File("/Users/kailu/test.html"));
		//PrintStream stdout = new PrintStream(System.out,true,"utf8");
		//System.setOut(stdout);
		String url = "http://www.mitbbs.com/article_t/JobHunting/32656365.html";
		//url = "http://news.baidu.com";
		String page = HTML_Downloader.download(url);
		
		//	page = new String(page.getBytes("GB2312"),"UTF8");
		
		// System.out.println(page);
		String[] xpaths = new String[]{
				"//table/tr/td/p",
		//		"//td[@class='jiawenzhang-type']/p"
			
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

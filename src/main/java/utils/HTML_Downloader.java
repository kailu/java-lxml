package utils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

public class HTML_Downloader {

	
	public static String download(String urlStr){
		URL url;
		    InputStream is = null;
		    BufferedReader br;
		    String line;
		    StringBuilder sb = new StringBuilder();
		    try {
		        url = new URL(urlStr);
		        is = url.openStream();  // throws an IOException
		        br = new BufferedReader(new InputStreamReader(is));

		        while ((line = br.readLine()) != null) {
		            sb.append(line);
		        }
		    } catch (MalformedURLException mue) {
		      //   mue.printStackTrace();
		    } catch (IOException ioe) {
		      //   ioe.printStackTrace();
		    } finally {
		        try {
		            if (is != null) is.close();
		        } catch (IOException ioe) {
		            // nothing to see here
		        }
		    }
		return sb.toString();
	}
}

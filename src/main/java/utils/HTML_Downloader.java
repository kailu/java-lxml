package utils;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.LinkedList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.http.Header;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.util.EntityUtils;


public class HTML_Downloader {

	public static String detectEncoding(String html){
		Pattern p =  Pattern.compile("charset=[\"']?([^\"'>]*)",Pattern.CASE_INSENSITIVE);
		Matcher m = p.matcher(html);
		if(m.find()){
			return m.group(1);
		}
		 
		//not found
		return null;
	}
	public static String download(String urlStr){
		
		HttpClient client = HttpClientBuilder.create().build();
		HttpGet request = new HttpGet(urlStr);
		 
		// add request header
		final String USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:25.0) Gecko/20100101 Firefox/25.0";
		request.addHeader("User-Agent", USER_AGENT);
		HttpResponse response;
		try {
			response = client.execute(request);
			 	
			byte[] rawresponse = EntityUtils.toByteArray(response.getEntity());
			
			
			String encoding = HTML_Downloader.detectEncoding(new String(rawresponse));
			if(encoding != null){
				return new String(rawresponse,encoding);
			}else{
				return new String(rawresponse,"utf8");
			}
			
		}catch(IOException e){
			e.printStackTrace();
		}
		return "";

	}
}

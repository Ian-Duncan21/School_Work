import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.io.BufferedReader;    
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;

public class Document {
	private String rawBody, body, id;

	public Document(String rawText) throws IOException{
		StringReader docText = new StringReader(rawText);
		BufferedReader document = new BufferedReader(docText);
		String temp;

		while ((temp = document.readLine()) != null){
			String a[] = temp.split(">");
			if(a.length < 3){
				continue;
			} else {
				body = a[2];
				rawBody = a[2];
				body = formatArticle(body);
				id = parseID(a[1]);
			}
		}

		document.close();
		docText.close();
	}

	private String parseID(String headerText) {
		Pattern idPattern = Pattern.compile("(.*)<=+");
		Matcher idMatcher = idPattern.matcher(headerText);
		if (idMatcher.find()) {
			String idMatch = idMatcher.group(1);
			return idMatch;
		} else {
			return "";
		}
	}

	public String getArticleID() {
		return id;
	}

	public String getArticleBody() {
		return body;
	}

	public String getArticleRawText() {
		return rawBody;
	}

	private String formatArticle(String documentText) {
		documentText = documentText.toLowerCase();
		documentText = documentText.replaceAll("\\p{Punct}", "");
		return documentText;
	}

}

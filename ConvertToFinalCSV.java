import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class ConvertToFinalCSV {
	public static void main(String[] args){
		try (BufferedReader br = new BufferedReader(new FileReader("allCombined.csv"))) {
			FileWriter in = new FileWriter("results.csv");
			FileWriter gr = new FileWriter("grades.csv");
			String CSV_HEADER = "NewID,FileName,Compiled,Tests-Run,Tests-Correct,V-Pen,FinalScore\n";
			String GRADES_HEADER = "FirstName,LastName,Grade\n";	
			in.append(CSV_HEADER);
			gr.append(GRADES_HEADER);
			String line = br.readLine();
			while((line = br.readLine()) != null){
				String[] values = line.split(",");
				gr.append(values[1] + "," + values[2]);
				in.append(values[3] + "," + values[4]);
				if(values[4].equals("no")){
					in.append(",-,-,-,-,0\n");
					gr.append(",0\n");
					continue;
				}
				if(values[5].equals("yes")){
					in.append(",20");
				} else {
					in.append(",0,-,-,-,0\n");
					gr.append(",0\n");
					continue;
				}
				if(values.length < 7 || values[6].equals("-")) {
					in.append(",indefinite,indefinite,indefinite,20\n");
					gr.append(",20\n");
					continue;
				}
				double TRPts = Double.parseDouble(values[6]) * 40;
				in.append("," + TRPts);
				double TCPts = Double.parseDouble(values[7]) * 40;
				in.append("," + TCPts);
				double VPen;				
				if(values.length < 9 || values[8].equals("-")) {
					in.append(",indefinite");
					VPen = 30;
				} else {
				 	VPen = 2*Math.log10(Double.parseDouble(values[8]) + Double.parseDouble(values[9]) + Double.parseDouble(values[10]) + Double.parseDouble(values[11]) + 1);
			
					if(VPen > 30) VPen = 30;
					in.append(",-" + new DecimalFormat("#.0#").format(VPen));
				}
				Double finalScore = TRPts + TCPts + 20 - VPen;
				if(finalScore < 20) finalScore = 20.0; 				
				in.append("," + Math.round(finalScore) + "\n");
				gr.append(","+ Math.round(finalScore) +"\n");
			}					
			in.close();
			gr.close();
			br.close();
		} catch (IOException e){
			System.out.println(e.getMessage());
		}
	}
}

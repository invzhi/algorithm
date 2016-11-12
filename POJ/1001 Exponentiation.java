import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
    public static void main(String[] args) {
        BigDecimal R;
        int n, begin, end;
        String s;
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            R = in.nextBigDecimal();
            n = in.nextInt();
            R = R.pow(n);
            s = new String(R.toPlainString());
            begin = 0;
            end = s.length() - 1;
            while (s.charAt(begin) == '0') begin++;
            while (s.charAt(end) == '0') end--;
            if (s.charAt(end) == '.') end--;
            for (int i = begin; i <= end; i ++) System.out.print(s.charAt(i));
            System.out.println();
        }
        System.exit(0);
    }
}
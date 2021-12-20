package 剑指offer.Day3;


import java.util.HashSet;

/**
 * 空格替换成 %20
 */
public class Q1 {

    public static String replaceSpace(String s) {
        int count = 0;
        HashSet<Integer> mySet = new HashSet<>();
        for(int i = 0 ; i< s.length();i++) {
            if (s.charAt(i) == ' ') {
                count++;
                mySet.add(i);
            }
        }

        char[] resChar = new char[count*2 + s.length()];
        int tempC = 0;
        for (int i = 0 ; i< s.length(); i++){
            if (mySet.contains(i)){
                resChar[tempC] = '%';
                resChar[tempC+1] = '2';
                resChar[tempC+2] = '0';
                tempC = tempC+3;
            }
            else {
                resChar[tempC] = s.charAt(i);
                tempC++;
            }
        }
        return new String(resChar);

    }

    public static void main(String[] args) {
        String myString = "Hello World 123";
        System.out.println(Q1.replaceSpace(myString));
    }
}

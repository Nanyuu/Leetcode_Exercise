package 剑指offer.Day3;


/**
 * 给定一个字符串 和 一个数字n
 * 按照数字 延后前n个字符，然后
 */
public class Q2 {
    public static String reverseLeftWords(String s, int n) {
        // 如果n>s.len 则不反转
        if (n >= s.length()){
            return s;
        }

        // 保存前n个字符
        char[] myCharArray = s.substring(0,n).toCharArray();

        char[] resChar = s.toCharArray();

        int left = 0;
        for(int right = n ; right< s.length(); right ++){
            resChar[left] = resChar[right];
            left++;
        }

        for (int right = 0 ; right < n ; right++){
            resChar[left] = myCharArray[right];
            left++;
        }
        return new String(resChar);
    }

    public static void main(String[] args) {

    }
}

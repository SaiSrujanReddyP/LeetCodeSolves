class Solution {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) return 0;
        int index = 0, length = s.length();
        int sign = 1;
        long number = 0;
        while (index < length && s.charAt(index) == ' ') index++;
        if (index < length && (s.charAt(index) == '+' || s.charAt(index) == '-')) {
            sign = s.charAt(index) == '-' ? -1 : 1;
            index++;
        }
        while (index < length && Character.isDigit(s.charAt(index))) {
            int digit = s.charAt(index) - '0';
            number = number * 10 + digit;
            if (sign == 1 && number > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (sign == -1 && -number < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            index++;
        }
        return (int) (number * sign);
    }
}

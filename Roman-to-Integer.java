import java.util.HashMap;
import java.util.Map;

class Solution {
    public int romanToInt(String romanNumeral) {
        Map<Character, Integer> romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);
        int result = 0;
        for (int index = 0; index < romanNumeral.length(); index++) {
            int currentValue = romanMap.get(romanNumeral.charAt(index));
            if (index + 1 < romanNumeral.length()) {
                int nextValue = romanMap.get(romanNumeral.charAt(index + 1));
                if (currentValue < nextValue) {
                    result -= currentValue;
                    continue;
                }
            }
            result += currentValue;
        }
        return result;
    }
}

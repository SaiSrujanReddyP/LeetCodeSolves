import java.util.Arrays;

class Solution {
    public int[] successfulPairs(int[] spellPowers, int[] potionStrengths, long successThreshold) {
        Arrays.sort(potionStrengths);
        int[] result = new int[spellPowers.length];
        int totalPotions = potionStrengths.length;

        for (int i = 0; i < spellPowers.length; i++) {
            long spellPower = spellPowers[i];
            long minPotionNeeded = (successThreshold + spellPower - 1) / spellPower;

            int firstValidIndex = findFirstPotion(potionStrengths, minPotionNeeded);
            result[i] = totalPotions - firstValidIndex;
        }

        return result;
    }

    private int findFirstPotion(int[] potions, long target) {
        int left = 0, right = potions.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

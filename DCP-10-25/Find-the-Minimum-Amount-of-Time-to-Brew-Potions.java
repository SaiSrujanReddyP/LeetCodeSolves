class Solution {

    public long minTime(int[] skill, int[] mana) {
        int numWizards = skill.length;
        int numPotions = mana.length;

        long[] finishTime = new long[numWizards];

        for (int potion = 0; potion < numPotions; potion++) {
            long currentWizardTime = 0;

            for (int wizard = 0; wizard < numWizards; wizard++) {
                long startTime = Math.max(currentWizardTime, finishTime[wizard]);
                long timeNeeded = (long) skill[wizard] * mana[potion];
                long endTime = startTime + timeNeeded;
                currentWizardTime = endTime;
            }

            finishTime[numWizards - 1] = currentWizardTime;

            for (int wizard = numWizards - 2; wizard >= 0; wizard--) {
                long timeForNextWizard = (long) skill[wizard + 1] * mana[potion];
                finishTime[wizard] = finishTime[wizard + 1] - timeForNextWizard;
            }
        }

        return finishTime[numWizards - 1];
    }
}

import java.util.*;
class Solution {
    public String specialRankingSystem(String[] votes) {
        int k = votes[0].length();
        // count[team][position]
        int[][] count = new int[26][k];
        // Count votes
        for (String vote : votes) {
            for (int pos = 0; pos < k; pos++) {
                char ch = vote.charAt(pos);
                count[ch - 'A'][pos]++;
            }
        }

        for (int j = 0; j < 26; j++) {
            int max = 0;
            for (int i = 0; i < k; i++) {
                max = Math.max(max, count[j][i]);
            }
        }
        return "";
    }
}
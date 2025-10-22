import java.util.*;
class Solution {
  public int maxFrequency(int[] arr, int k, int operations) {
    Arrays.sort(arr);
    int answer = 0;
    Map<Integer,Integer> counts = new HashMap<>();
    Set<Integer> candidates = new TreeSet<>();

    for(int i = 0; i < arr.length; i++){
      int val = arr[i];
      int freq = 1;
      while(i + 1 < arr.length && arr[i+1] == val){
        freq++;
        i++;
      }
      counts.put(val, freq);
      answer = Math.max(answer, freq);

      candidates.add(val);
      if(val - k >= arr[0]) candidates.add(val - k);
      if(val + k <= arr[arr.length-1]) candidates.add(val + k);
    }

    for(int cand : candidates){
      int left = 0;
      int right = arr.length - 1;

      int l = 0;
      int r = arr.length - 1;
      while(l < r){
        int mid = (l+r)/2;
        if(arr[mid] < cand - k) l = mid+1;
        else r = mid;
      }
      left = l;

      l = 0;
      r = arr.length - 1;
      while(l < r){
        int mid = (l+r+1)/2;
        if(arr[mid] > cand + k) r = mid-1;
        else l = mid;
      }
      right = l;

      int temp;
      if(counts.containsKey(cand)){
        temp = Math.min(right - left + 1, counts.get(cand) + operations);
      } else {
        temp = Math.min(right - left + 1, operations);
      }
      answer = Math.max(answer, temp);
    }

    return answer;
  }
}

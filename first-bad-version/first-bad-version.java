/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1, r = n;
        int badVersion = -1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            boolean isBad = isBadVersion(mid);
            if(isBad) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
}
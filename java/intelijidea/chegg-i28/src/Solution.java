public class Solution {
    private static int max = 0;
    public static void main(String[] args){
        int[] a = {6,8,-9};
        int r = maxSum(a);
        System.out.println(r);
    }

    public static int maxSum(int[] a){
        sum(a, 0, a.length-1);
        return max;
    }

    public static int sum(int[] a, int l, int r){
        int res = 0;
        if(r-l == 0){
            if(max < a[l]){
                max = a[l];
            }
            return a[l];
        }else {
            int m = (l+(r-1))/2;
            int left = sum(a, l, m);
            int right = sum(a, m+1, r);
            if(max < left + right){
                max = left + right;
            }else if(max < max + left && max != left){
                max = left;
            }else if(max < max + right && max != right){
                max = right;
            }
            return (left+right);
        }
    }
}

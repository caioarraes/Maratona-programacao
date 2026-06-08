class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        
        int volumeMaximo = 0;

        while (left < right) {
            
            int largura = right - left;
            int alturaLmite = min(height[left], height[right]);
            
            int CalculoVolumeAgua = largura * alturaLmite;
            
            volumeMaximo = max(volumeMaximo, CalculoVolumeAgua);

            if (height[left] < height[right]) {
                left++; 
            } else {
                right--; 
            }
        }
        
        return volumeMaximo;
    }
};

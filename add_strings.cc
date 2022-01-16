class Solution {
public:
    string addStrings(string num1, string num2) {
      int output_length = std::max(num1.length(), num2.length()) + 1;
      string output(output_length, ' ');
      int output_index = output_length - 1;
      int num1_index = num1.length() - 1;
      int num2_index = num2.length() - 1;
      int carry_over = 0;
      while (num1_index >= 0 || num2_index >= 0) {
        int n1 = num1_index >= 0 ? num1[num1_index] - '0' : 0;
        int n2 = num2_index >= 0 ? num2[num2_index] - '0' : 0;
        int sum = (n1 + n2 + carry_over) % 10;
        carry_over = (n1 + n2 + carry_over) / 10;
        output[output_index--] = '0' + sum;
        --num1_index;
        --num2_index;
      }
      if (carry_over > 0) {
        output[output_index--] = '0' + carry_over;
      }
      if (output_index >= 0) {
        // Return without first character
        return output.substr(1);
      }
      return output;
    }
};

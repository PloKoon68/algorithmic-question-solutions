
class Main {   
    public static void main(String[] args) {        
        int count = 0;

        for(int i = 10; i <= 1000000; i++) {
            boolean isRight = false;

            int num = i;
            int digit = num % 10;
            num /= 10;
            while(num > 0) {
               int temp = num%10;
               if(temp == digit) {
                   if(!isRight)
                       isRight = true;
                   else {
                       isRight = false;
                       break;
                   }
               }
               num /= 10;
               digit = temp;
            }

            if(isRight)
                count++;
        }

    }
}

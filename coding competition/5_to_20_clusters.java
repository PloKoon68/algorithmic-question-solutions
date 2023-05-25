/*
If clusters among the numbers from1 to 20 are formed with digits varying between 5and 20,
how many of these sets will have the sum of 75 for its digits?
*/



public class Main {

    static int count;

    public static void main(String[] args) {
        for(int i = 5; i < 21; i++)
            func(i, 1, 0, 1);

        System.out.println(count);
    }



    public static void func(int border, int start, int sum, int dimension) {
        for(int i = start; i < 21; i++) {
            if(dimension != border) {

                func(border, i + 1, sum + i, dimension + 1);

            }
            else
                if(sum + i == 75)
                    count++;

        }
    }  
}

/*
Write the program that multiplies the following 2 numbers:
66599378465230093486116254292784885120034524787326511514784875935564789331299 x
96523655221478545854556939175894233659871245879654585411287325464468700021547
*/



class Main {
    public static void main(String[] args) {
        int []say1={6,6,5,9,9,3,7,8,4,6,5,2,3,0,0,9,3,4,8,6,1,1,6,2,5,4,2,9,2,7,8,4,8,8,5,1,2,0,0,3,4,5,2,4,7,8,7,3,2,6,5,1,1,5,1,4,7,8,4,8,7,5,9,3,5,5,6,4,7,8,9,
                3,3,1,2,9,9};

        int [] say2={9,6,5,2,3,6,5,5,2,2,1,4,7,8,5,4,5,8,5,4,5,5,6,9,3,9,1,7,5,8,9,4,2,3,3,6,5,9,8,7,1,2,4,5,8,7,9,6,5,4,5,8,5,4,1,1,2,8,7,3,2,5,4,6,4,4,6,8,7,0,0,
                0,2,1,5,4,7};
        int y=299;
        int satır=0;
        int elde=0;
        int[][] say3=new int[77][155];


        int sütun, x = 154;

        int[] sonuç=new int[300];
        for(int i=0;i<300;i++)
            sonuç[i]=0;


        for(int i =76;i>=0;i--){
            sütun=x;
            for(int j=76;j>=0;j--){
                say3[satır][sütun]=(say1[i]*say2[j]+elde)%10;
                elde=(say1[i]*say2[j]+elde)/10;
                sütun--;
            }
            if(elde!=0)
                say3[satır][sütun]=elde;
            satır++;
            x--;
            elde = 0;
        }


        int digitSum;

        for(int j=154;j>=0;j--) {
            digitSum = 0;
            for(int i=0;i<77;i++){
                digitSum +=say3[i][j];
            }
            sonuç[y]=digitSum;
            y--;
        }



        elde = 0;
        for(int i=298; i >= 0; i--) {
            sonuç[i] += elde;
            elde=sonuç[i]/10;
            sonuç[i]%=10;
        }

        for(int i = 146; i < 300; i++)
            System.out.print(sonuç[i]);
        
    }
}

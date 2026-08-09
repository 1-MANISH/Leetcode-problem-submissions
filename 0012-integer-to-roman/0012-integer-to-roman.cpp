class Solution {
public:
     string intToRoman(int n) {
        map<int ,string>roman;
        roman[1]="I";
        roman[4]="IV";
        roman[5]="V";
        roman[9]="IX";
        roman[10]="X";
        roman[40]="XL";
        roman[50]="L";
        roman[90]="XC";
        roman[100]="C";
        roman[400]="CD";
        roman[500]="D";
        roman[900]="CM";
        roman[1000]="M";
        
        int a[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        int i=12;
        string ans="";
        while(i>=0)
        {
            int qua=n/a[i];
            n=n%a[i];
            while(qua>0){
                ans+=roman[a[i]];
                qua--;
            }
            i--;
        }
        return ans;
        
    }
};
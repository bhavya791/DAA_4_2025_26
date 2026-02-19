int superDigit(string n, int k) {
    
    long long sum=0;
    
    for(int i=0;i<n.size();i++){
       sum=sum + (n[i]-'0');
    }
    
    sum=sum*k;
    
    while(sum>9){
        long long temp=0;
        while(sum>0){
            temp=temp+(sum%10);
            sum=sum/10;
        }
        sum=temp;
    }
    return sum;

}

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1=0;
        long long num2=0;
        long long mod=1000000007;
        while(first!=nullptr)
        {
            num1=(num1*10+first->data)%mod;
            first=first->next;
        }
         while(second!=nullptr)
        {
            num2=(num2*10+second->data)%mod;
            second=second->next;
        }
        return (num1* num2)%mod;
    }
};

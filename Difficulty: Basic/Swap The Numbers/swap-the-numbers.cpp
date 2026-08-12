void swap(int &a, int &b) {
    // code here
    int temp = a^b;
    a = temp^a;
    b = a^temp;
}

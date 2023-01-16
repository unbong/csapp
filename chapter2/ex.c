#include <stdio.h>
int copyLSB(long x )
{
    
    long xLSB = x & 1L;
    printf(" '& op' %.16x \n", xLSB);

    xLSB = xLSB << 63;
    printf(" 'left shift' %.16x \n", xLSB);

    xLSB = xLSB >> 63;
    printf(" 'right shift' %.16x \n", xLSB);
    return xLSB;
}

long allOddBits(long x) {

    long oddBits = x & 0x5555555555555555L;
    //oddBits = oddBits ^ 0x5555555555555555L;
    oddBits = oddBits ^ 0xAAAAAAAAAAAAAAAAL;
    return !oddBits;
}

long isNotEqual(long x, long y) {

    long isZero = x ^ y;
    isZero = !isZero;
    
    return  !isZero;
}

long dividePower2(long x, long n) {
    
    long highestBit = x >> 63;
    highestBit = highestBit & 1L;
    long bias = highestBit << n;
    long singFlg = x & 0x8000000000000000;
    long bias2 = singFlg>>63;
    bias = bias + bias2;
    long deviedVal = x + bias;
    deviedVal = deviedVal >> n;

    
    return deviedVal;
}


long remainderPower2(long x, long n) {

    // 
   // make negative to positive
    long inverse = x & 0x8000000000000000L;
    inverse = inverse >> 62;

    x = x ^ inverse;

    //  and operate  x and 2^k-1
    long modNum = 1 << n;
    modNum = modNum + 0xFFFFFFFFFFFFFFFFL;
    long remain = x & modNum;

    // inverse remain
    remain = remain ^ inverse;

    return remain;
}


long rotateLeft(long x, long n) {

    // 将x的 向右移动63-n
    long rsh63_n = 63-n; 
    rsh63_n = rsh63_n+1;
    long rsh63_n_bit = x >>  rsh63_n;
    //  将63-n位 0与 n位1 做且处理
    long mask = 0xFFFFFFFFFFFFFFFFL;
    mask = mask << n;
    mask = mask ^ 0xFFFFFFFFFFFFFFFFL;
    rsh63_n_bit = rsh63_n_bit & mask;
    // 将x向左移动 n位
    long lsh_n_x = x << n;
    
    // 将x与 前N位x（已向右移动）处理的值相加
    long rotateLeft = lsh_n_x + rsh63_n_bit;

    return rotateLeft;
}

long bitMask(long highbit, long lowbit) {
     
     // 将FFFF 左移lowbit
     long low = 0xFFFFFFFFFFFFFFFFL << lowbit ; 
     // 将FFFF 左移highbit +1 
    long high = 0xFFFFFFFFFFFFFFFFL << highbit ; 
    high = high<<1;
     // 将高位 地位的变量 执行异或操作
    long bitMask = low ^ high;
    // 将and 操作后的值 与lowbit 做 and 操作
    bitMask = bitMask & low;

    return bitMask;
}

long isPower2(long x) {
    
    long isPower2 = x << 2;


    return 2L;
}

long trueThreeFourths(long x) {

    // x / 2 + x / 4

    long x_dev2 = dividePower2(x, 1);
    long x_dev4 = dividePower2(x,2);
    return x_dev2 + x_dev4;
}


int main(int argc, char const *argv[])
{

    long dev = trueThreeFourths(11L);
    printf("dev exp 8 , %ld \n", dev);

    dev = trueThreeFourths(-9L);
    printf("dev exp -6 , %ld \n", dev);

    long mask = bitMask(5L,3L);
    printf("mask exp 0x38L , %#16x \n", mask);

    mask = bitMask(3L,5L);
    printf("mask exp 0x0L , %#16x \n", mask);

    long left = rotateLeft(0x8765432187654321L,4L);
    char ch = 0xC0;
    printf("left exp 0x7654321876543218L , %#8x \n", left);


    long remain = remainderPower2(-9223372036854775808L,0L);
    printf("remain exp 2 %ld \n",remain);

    remain = remainderPower2(-9223372036854775808L,0L);
    printf("remain exp 0 %ld \n",remain);

    long devide = dividePower2(9223372036854775807L, 0L);
    printf("devide exp 9223372036854775807L %ld \n",devide);

    devide = dividePower2(-9223372036854775808L, 0L);
    printf("devide2 exp  -9223372036854775808L %ld \n",devide);

    long equal = isNotEqual(-9223372036854775808L, -9223372036854775808L);
    printf("exp  1 %ld \n",equal);

    equal = isNotEqual(112L, 12L);
    printf("%ld \n",equal);
    

    long s = allOddBits(-9223372036854775808L);
    printf("exp 0,  %ld \n", s);
    s = allOddBits(9223372036854775807L);
    printf(" exp 1,  %ld \n", s);
    s = allOddBits(-2L);
    printf(" exp 1,  %ld \n", s);

    /* code */
    copyLSB(5L);
    copyLSB(6L);
}



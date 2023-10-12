/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/


#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[50] ;
    double Salary ;
} ;

// ฟังก์ชันคำนวณภาษี
double CalculateTax( double salary ) {
    return salary * 0.07 ;
}

int main() {
    int n = 0 ;
    double totalSalaryPerYear = 0 ;
    double totalTax = 0 ;
    char maxTaxName[50] = "" ;
    double maxTax = 0 ;

    printf( "Employee 1's Name : " ) ;
    char choice[50] ;
    scanf( " %s" , choice ) ;

    while ( strcmp("-1", choice) != 0 ) {
        struct Employee emp ;

        printf("Salary (Bath/Month) : ") ; 
        scanf("%lf", &emp.Salary) ;

        n++ ;

        double salaryPerYear = emp.Salary * 12 ;
        double tax = CalculateTax( salaryPerYear ) ;

        totalSalaryPerYear += salaryPerYear ;
        totalTax += tax ;

        if ( tax > maxTax ) {
            maxTax = tax ;
            strcpy( maxTaxName , emp.Name ) ;
        }

        printf( "Employee %d's Name : " , n + 1 ) ;
        scanf( " %s" , choice ) ;
    }

    printf( "All salary per month: %.2lf Bath\n" , totalSalaryPerYear / 12 ) ;
    printf( "All salary per year: %.2lf Bath\n" , totalSalaryPerYear ) ;
    printf( "Tax (7%% per year) : %.2lf Bath\n" , totalTax ) ;
    printf( "Most tax in company : %s (%.2lf Bath per year)\n" , maxTaxName , maxTax ) ; 

    return 0 ;
}

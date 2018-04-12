#include <iostream>

#include "matrix.h"
#include "utils.h"

#define EXEC_TIMES 5000000

using namespace std;

/***** TASK 1 *****/
void task1() {
    enable_print_step();
    cout << "########## TASK 1 ##########" << endl;

    int m[] = {1, 2, 3, 4, 5, 6};
    Matrix mat(m, 2, 3);

    cout << "-- copy constructor --" << endl;
    Matrix mat_a(mat);
    cout << "-- move constructor --" << endl;
    Matrix mat_b(move(mat));

    Matrix mat_c, mat_d;
    cout << "-- assignment --" << endl;
    mat_c = mat_a;
    cout << "-- move assignment --" << endl;
    mat_d = move(mat_b);

    cout << "-- print --" << endl;
    // TODO: Please comment the line(s) which may cause runtime error. TA may ask you to explain the reason.
    cout << "mat_a = " << endl; mat_a.print();

    /* After being move assigned to mat_d, all data members of mat_b has been reset to 0 or nullptr,
     * so it may cause a read access violation when mat_b.print() trys to access ptr[index].
     * But in fact, mat_b.print() will just do nothing because the loop in it won't be entered given num_rows = 0.
     */
    // cout << "mat_b = " << endl; mat_b.print();
    
    cout << "mat_c = " << endl; mat_c.print();
    cout << "mat_d = " << endl; mat_d.print();

    cout << endl;
}

/***** TASK 2 *****/
void task2() {
    cout << "########## TASK 2 ##########" << endl;
    int m_a[16], m_b[16];
    for (int i = 0; i < 16; i++) {
        m_a[i] = i;
        m_b[i] = i * 3;
    }
    Matrix mat_a(m_a, 4, 4), mat_b(m_b, 4, 4), mat_c(mat_b);
    Matrix mat_result;
    mat_result = mat_a + mat_b;
    cout << "mat_a + mat_b = " << endl; mat_result.print(); cout << endl;

    cout << "mat_result(1, 1) = " << mat_result(1, 1) << endl; cout << endl;

    disable_print_step();
    long t0, t1;    // for time recording
    t0 = current_time_millis();
    Matrix mat_p = mat_b;
    for (int i = 0; i < EXEC_TIMES; i++)
        mat_p = mat_p + mat_b;
    cout << "mat_p = " << endl; mat_p.print();
    t1 = current_time_millis();
    cout << "time cost: " << (t1 - t0) << "ms" << endl; cout << endl;

    t0 = current_time_millis();
    Matrix mat_q = mat_b;
    for (int i = 0; i < EXEC_TIMES; i++)
        mat_q = mat_b + move(mat_q);
    cout << "mat_q = " << endl; mat_q.print();
    t1 = current_time_millis();
    cout << "time cost: " << (t1 - t0) << "ms" << endl;
}


int main() {
    task1();
    task2();
    return 0;
}
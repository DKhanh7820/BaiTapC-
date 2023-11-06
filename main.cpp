#include <iostream>
#include <vector>
#include <string>
#include<list>
#include <stdbool.h>


using namespace std;

float toan;
float ly;
float hoa;
string ten;
int tuoi;
int gioitinh;
string khoahoc;
string lichhoc;

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

typedef enum{
    THEO_TEN,
    THEO_MSSV,
    THEO_DIEM_TRUNG_BINH
}TypeSapXep;

//sắp xếp theo điểm trung bình
bool compareDTB(list<SinhVien>::iterator it1, list<SinhVien>::iterator it2);
//sắp xếp theo tên
bool compareTheoTen(list<SinhVien>::iterator it1, list<SinhVien>::iterator it2);
//hàm chứa Danh sách và con trỏ hàm sắp xếp
void sort(list<SinhVien> data, bool (*compareFunc)(list<SinhVien>::iterator , list<SinhVien>::iterator ));


class DoiTuong{
    protected:
        string TEN;
        int TUOI;
        TypeGioiTinh GioiTinh;
        int ID;
    public:
        DoiTuong(){
            static int id;
            ID = id;
            id++;
        };
        void setTen(string ten){
            TEN = ten;
        }
        string getTen(){
            return TEN;
        }
        void setTuoi(int tuoi){
            TUOI = tuoi;
        }
        int getTuoi(){
            return TUOI;
        }
        void setGT(int gioiTinh){
            GioiTinh = (TypeGioiTinh)gioiTinh;
        }
        TypeGioiTinh getGT(){
            switch (GioiTinh)
            {
            case NAM:
                printf("NAM");
                break;
                case NU:
                printf("NU");
                break;
            default:
                break;
            }
            return GioiTinh;
        }
};

class SinhVien : public DoiTuong{
    private:
        float monToan;
        float monLy;
        float monHoa;
        string KhoaHoc;
        string LichHoc;
    public:
        SinhVien(float toan = 0, float ly = 0, float hoa = 0, string khoahoc = "", string lichhoc = "")
        : monToan(toan), monLy(ly), monHoa(hoa), KhoaHoc(khoahoc), LichHoc(lichhoc) 
                    {
                    }
        int getMSSV(){
            return ID;
        }

        void setDiemToan(float toan){
            monToan = toan;
        }
        float getDiemToan(){
            return monToan;
        }
        void setDiemLy(float ly){
            monLy = ly;
        }
        float getDiemLy(){
            return monLy;
        }
        void setDiemHoa(float hoa){
            monHoa = hoa;
        }
        float getDiemHoa(){
            return monHoa;
        }
        void setKhoaHoc(string khoahoc){
            KhoaHoc = khoahoc;
        }
        string getKhoaHoc(){
            return KhoaHoc;
        }
        void setLichHoc(string lichhoc){
            LichHoc = lichhoc;
        }
        string getLichHoc(){
            return LichHoc;
        }
        float getDiemTrungBinh(){
            return (monToan + monLy + monHoa)/3;
        }
        TypeHocLuc getHocLuc(){
            if(getDiemTrungBinh() >= 8.0){
                return GIOI;
            }else if(getDiemTrungBinh()>= 7.0){
                return KHA;
            }else if(getDiemTrungBinh() >= 5.0){
                return TRUNG_BINH;
            }else{
                return YEU;
            }
        }

};

class GiangVien : public DoiTuong{
    private:
        string MonHoc;
        string LichLamViec;
    public:
        GiangVien(string course = "", string workSchedule = "") : MonHoc(course), LichLamViec(workSchedule){
        } 
        int getMSGV(){
            return ID;
        }
        void setMonHoc(string monhoc){
            MonHoc = monhoc;
        }
        string getMonHoc(){
            return MonHoc;
        }
        void setLichLamViec(string workSchedule){
            LichLamViec = workSchedule;
        }
        string getLichLamViec(){
            return LichLamViec;
        }
};

class MenuSinhVien{
    private:
        list<SinhVien> Database;
    public:
        void themSinhVien(SinhVien sv);
        void xoaSinhVien(int mssv);
        void suaSinhVien(int mssv);
        list<SinhVien> danhSachSinhVien();
        void sapXepSinhVien(int sapXep);
};

//Thêm sinh viên
void MenuSinhVien::themSinhVien(SinhVien sv){
    Database.push_back(sv);    
}
// Danh sách sinh viên
list<SinhVien> MenuSinhVien::danhSachSinhVien(){
        cout << "Danh sach sinh vien:\n";
        list<SinhVien>::iterator i;
    for (i = Database.begin(); i != Database.end(); i++) {
        SinhVien sv = *i;
        cout << "MSSV: " << sv.getMSSV() << endl;
        cout << "Diem Toan: " << sv.getDiemToan() << endl;
        cout << "Diem Ly: " << sv.getDiemLy() << endl;
        cout << "Diem Hoa: " << sv.getDiemHoa() << endl;
        cout << "Ten sinh vien: " << sv.getTen() << endl;
        cout << "Tuoi sinh vien: " << sv.getTuoi() << endl;
        cout << "Khoa hoc sinh vien: "<< sv.getKhoaHoc() << endl;
        cout << "Lich hoc sinh vien: "<< sv.getLichHoc() << endl;
        cout << "Gioi tinh sinh vien: ";
        cout << sv.getGT();
        cout << endl;
        cout <<"------------------"<<endl;
    }
    return Database;
}
// xóa sinh viên
void MenuSinhVien::xoaSinhVien(int mssv){
    list<SinhVien>::iterator i;
    bool found = false; // biến kiểm tra MSSV có xuất hiện không
    for(i = Database.begin(); i != Database.end(); i++){
        if(i->getMSSV() == mssv){
            i = Database.erase(i);
            found = true;
            cout<<"Da xoa sinh vien co MSSV: "<<mssv<<endl;
            break;
        }
    }
    if(!found){
        cout<<"Khong tim thay MSSV: "<<mssv<<endl;
        cout <<"------------------"<<endl;
    }
}
// hàm sửa sinh viên
void MenuSinhVien::suaSinhVien(int mssv){
    bool found = false; // biến kiểm tra MSSV có xuất hiện không
    list<SinhVien>::iterator i;
    for(i = Database.begin(); i != Database.end(); i++){
        if(i->getMSSV() == mssv){

            //sửa thông tin:
            cout<<"Nhap diem toan: ";
            cin>>toan;
            cout<<"Nhap diem ly: ";
            cin>>ly;
            cout<<"Nhap diem hoa: ";
            cin>>hoa;
            cout<<"Nhap ten: ";
            cin.ignore();
            getline(cin,ten);
            cout<<"Nhap tuoi: ";
            cin>>tuoi;
            cout<<"Nhap khoa hoc: ";
            cin.ignore();
            getline(cin,khoahoc);
            cout<<"Nhap lich hoc: ";
            cin.ignore();
            getline(cin,lichhoc);
            cout<<"Nhap gioi tinh(0 NAM 1 NU): ";
            cin>>gioitinh;
            //
            SinhVien sv;
            i->setDiemToan(toan);
            i->setDiemLy(ly);
            i->setDiemHoa(hoa);
            i->setTen(ten);
            i->setTuoi(tuoi);
            i->setKhoaHoc(khoahoc);
            i->setLichHoc(lichhoc);
            i->setGT(gioitinh);
            found = true;
            cout<<"Da sua sinh vien co MSSV: "<<mssv<<endl;
            break;
        }
    }
    if(!found){
        cout<<"khong tim thay MSSV: "<<mssv<<endl;
    }
}
// hàm sắp xếp sinh viên
void MenuSinhVien::sapXepSinhVien(int sapXep){
    TypeSapXep sapxep;
    sapxep = (TypeSapXep)sapXep;
    switch (sapxep)
    {
     case THEO_DIEM_TRUNG_BINH:
      sort(Database, &compareDTB);
     break;
     case THEO_TEN:
      sort(Database, &compareTheoTen);
     break; 
     default:
     break;
    }
}

// sắp xếp theo điểm trung bình
bool compareDTB(list<SinhVien>::iterator it1, list<SinhVien>::iterator it2){
    if(it1->getDiemTrungBinh() > it2->getDiemTrungBinh()){
        return true;
    }
    return false;
}
//sắp xếp theo tên
bool compareTheoTen(list<SinhVien>::iterator it1, list<SinhVien>::iterator it2){
    if(it1 ->getTen() > it2 -> getTen()){
        return true;
    }
    return false;
}

// hàm sắp xếp từ bé đến lớn
void sort(list<SinhVien> data, bool (*compareFunc)(list<SinhVien>::iterator , list<SinhVien>::iterator )){
    list<SinhVien>::iterator it1;
    list<SinhVien>::iterator it2;
    for(it1 = data.begin(); it1 != data.end(); it1++){
        it2 = data.begin();
        it2++;
        SinhVien temp;
        for(it2; it2 != data.end(); it2++){
            if(compareFunc(it1, it2) == true){
                temp = *it1;
                *it1 = *it2;
                *it2 = temp;
            }
        }
    }
    
}



int main(int argc, char const *argv[])
{
    int nhap;
    MenuSinhVien mn;
    //SinhVien sv;
    do{
        cout<<"Thong tin sinh vien"<<endl;
        cout<<"1. Them sinh vien"<<endl;
        cout<<"2. Xoa sinh vien"<<endl;
        cout<<"3. Sua sinh vien"<<endl;
        cout<<"4. Danh sach sinh vien"<<endl;
        cout<<"5. Sap xep sinh vien"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Nhap lua chon: ";
     
        cin>>nhap;
    
    if(nhap == 1){
        cout << "Nhap diem toan: ";
        cin >> toan;
        cout << "Nhap diem ly: ";
        cin >> ly;
        cout << "Nhap diem hoa: ";
        cin >> hoa;
        cout << "Nhap ten sinh vien: ";
        cin >> ten;
        getline(cin, ten);
        cout << "Nhap tuoi sinh vien: ";
        cin >> tuoi;
        cout << "Nhap khoa hoc sinh vien: ";
        cin >> khoahoc;
        cout << "Nhap lich hoc sinh vien: ";
        cin >> lichhoc;
        cout << "Nhap gioi tinh (0 NAM, 1 NU): ";
        cin >> gioitinh;
        SinhVien sv;
        sv.setDiemToan(toan);
        sv.setDiemLy(ly);
        sv.setDiemHoa(hoa);
        sv.setTen(ten);
        sv.setTuoi(tuoi);
        sv.setKhoaHoc(khoahoc);
        sv.setLichHoc(lichhoc);
        sv.setGT(gioitinh);
        mn.themSinhVien(sv);
    }
    else if(nhap == 2){
        int mssv;
        cout<<"Nhap vao MSSV: ";
        cin>>mssv;
        mn.xoaSinhVien(mssv);
    }
    else if(nhap == 3){
        int mssv;
        cout<<"Nhap vao MSSV: ";
        cin>>mssv;
        mn.suaSinhVien(mssv);
    }
    else if(nhap == 4){
        mn.danhSachSinhVien();
    }
    else if(nhap == 5){

        int sapxep;
        cout<<"Chon kieu sap xep(0: theoTen 1: theoMSSV 2: theoDTB): ";
        cin>>sapxep;
        mn.sapXepSinhVien(sapxep);
    }

}
    while(nhap != 0);
    
    return 0;
}

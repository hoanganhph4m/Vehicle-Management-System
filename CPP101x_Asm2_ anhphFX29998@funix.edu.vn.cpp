//include các thư viện
#include <iostream>
#include <string>
using namespace std;
//Khai báo các biến, hàm, struct
enum LOAI_HANG_HOA
{
    NONG_SAN = 1,
    THUY_SAN,
    HANG_TIEU_DUNG,

};

struct XE_TAI
{
    int quangDuong;
    int taiTrong;
    LOAI_HANG_HOA loaiHangHoa;
    float mucTieuHaoNhienLieu;
    int vanTocTrungBinh;
    void nhapTTXeTai(int &);
    void xuatTTXeTai();
};

struct XE_BUYT
{
    int soGhe;
    int quangDuong;
    int thoigianChayMoichuyen;
    float mucTieuHaoNhienLieu;
    int vanTocTrungBinh;
    int SLKDiQuangDuongNgan;
    int SLKDiQuangDuongTrungBinh;
    int SLKDiQuangDuongDai;
    int tienVeThuDuoc;
    float TGTrungBinhXeChayGiua2Tram;
    void nhapTTXeBuyt(int &);
    void xuatTTXeBuyt();
    
};

struct XE_TAXI
{
    int quangDuong;
    int thoiGianCho;
    float mucTieuHaoNhienLieu;
    int vanTocTrungBinh;
    string diemDen;
    string diemDi;
    void nhapTTXeTaXi(int &);
    void xuatTTXeTaXi();
};


//Khai báo thân hàm

void XE_TAI::nhapTTXeTai(int &check) {
    int qd, tt,lhh, vttb;
    float mthnl;
    check++;// kiem tra xem user đã nhập tt trước khi xuất tt chưa
    cout << "Nhap quang duong(km): ";
    cin >> qd;
    cout << "Nhap tai trong(kg): ";
    cin >> tt;
    cout << "Nhap loai hang hoa: "<<endl ;
    cout << "1. Nong san" << endl;
    cout << "2. Thuy san"<< endl;
    cout << "3. Hang tieu dung"<< endl;
    cin >> lhh;
    cout << "Muc tieu hao nhien lieu(so lit xang cho moi 100km): ";
    cin >> mthnl;
    cout << "Nhap van toc trung binh(km/h): ";
    cin >> vttb;
    
    this->quangDuong = qd;
    this->taiTrong = tt;
    this->loaiHangHoa = (LOAI_HANG_HOA)lhh;
    this->vanTocTrungBinh = vttb;
    this->mucTieuHaoNhienLieu = mthnl;
};

void XE_TAI::xuatTTXeTai() {
    int cuocVanTai;
    float chiPhiNhienLieu;
    cout << "Quang duong: ";
    cout << this->quangDuong <<" VND" << endl;
    
    cout << "Loai hang hoa: ";
    if (this->loaiHangHoa == 1) cout << "Nong san" << endl;
    else if (this->loaiHangHoa == 2) cout << "Thuy san" << endl;
    else if (this->loaiHangHoa == 3) cout << "Hang tieu dung" << endl;
    else cout << "Khong ro loai hang hoa" << endl;
    
    cout << "Gia cuoc van tai: ";
    if (this->loaiHangHoa == 1) {
        cuocVanTai = 500 * this->taiTrong * this->quangDuong;
        cout << cuocVanTai << endl;
    }
    else if (this->loaiHangHoa == 2) {
        cuocVanTai = 3000 * this->taiTrong * this->quangDuong;
        cout << cuocVanTai << " VND" << endl;
    }
    else if (this->loaiHangHoa == 3) {
        cuocVanTai = 1000 * this->taiTrong * this->quangDuong;
        cout << cuocVanTai<<" VND" << endl;
    }
    else cout << "Khong ro loai hang hoa" << endl;
    
    chiPhiNhienLieu = this->mucTieuHaoNhienLieu / 100 * this->quangDuong * 20000;
    cout << "Chi phi nhien lieu: " << chiPhiNhienLieu<<" VND" << endl;
     
    cout << "Doanh thu: ";
    cout << cuocVanTai - (int)chiPhiNhienLieu <<" VND" << endl;
};

void XE_BUYT::nhapTTXeBuyt(int & check) {
    int sg, qd, tgcmc, slkdqdn, slkdqdtb, slkdqdd, vttb;
    float  mthnl;
    check++;// kiem tra xem user đã nhập tt trước khi xuất tt chưa
    cout << "Nhap so ghe: ";
    cin >> sg;
    cout << "Nhap quang duong(km): ";
    cin >> qd;
    cout << "Nhap thoi gian chay moi chuyen(phut): ";
    cin >> tgcmc;
    cout << "Nhap muc tieu hao nhien lieu(so lit xang cho moi 100km): ";
    cin >> mthnl;
    cout << "Nhap van toc trung binh(km/h): ";
    cin >> vttb;
    cout << "Nhap so luong khach di quang duong ngan: ";
    cin >> slkdqdn;
    cout << "Nhap so luong khach di quang duong trung binh: ";
    cin >> slkdqdtb;
    cout << "Nhap so luong khach di quang duong dai: ";
    cin >> slkdqdd;
    
    this->soGhe = sg;
    this->quangDuong = qd;
    this->thoigianChayMoichuyen = tgcmc;
    this->mucTieuHaoNhienLieu = mthnl;
    this->vanTocTrungBinh = vttb;
    this->SLKDiQuangDuongNgan = slkdqdn;
    this->SLKDiQuangDuongTrungBinh = slkdqdtb;
    this->SLKDiQuangDuongDai = slkdqdd;
        
};


void XE_BUYT::xuatTTXeBuyt() {
    float chiPhiNhienLieu;
    this->TGTrungBinhXeChayGiua2Tram = 1 / ((float)this->vanTocTrungBinh / 60);// doi van toc trung binh sang (km/phut) roi lay quang duong chia van toc ra thoi gian TB
      
    cout << "Quang duong: "<< this->quangDuong << endl;
    cout << "So luong khach di quang duong ngan: " << this->SLKDiQuangDuongNgan << endl;
    cout << "So luong khach di quang duong trung binh: " << this->SLKDiQuangDuongTrungBinh << endl;
    cout << "So luong khach di quang duong dai: " << this->SLKDiQuangDuongDai << endl;
    this->tienVeThuDuoc = this->SLKDiQuangDuongNgan * 3000 + this->SLKDiQuangDuongTrungBinh + 7000 + this->SLKDiQuangDuongDai * 9000;
    cout << "Tien ve thu duoc la: " << this->tienVeThuDuoc << " VND" << endl;

    chiPhiNhienLieu = this->mucTieuHaoNhienLieu / 100 * (float)this->quangDuong * 20000;
    cout << "Chi phi nhien lieu: " << chiPhiNhienLieu << " VND" << endl;
    cout << "Doanh thu: " << this->tienVeThuDuoc-chiPhiNhienLieu << " VND" << endl;
    cout << "Thoi gian trung binh xe chay giua 2 tram: "  << this->TGTrungBinhXeChayGiua2Tram << " phut" << endl;
};

void XE_TAXI::nhapTTXeTaXi(int & check) {
    int qd, tgc, vttb;
    float mthnl;
    string dden, ddi;
    check++;// kiem tra xem user đã nhập tt trước khi xuất tt chưa

    cout << "Nhap quang duong(km): ";
    cin >> qd;
    cout << "Nhap thoi gian cho(phut): ";
    cin >> tgc;
    cout << "Nhap muc tieu hao nhien lieu(so lit xang cho moi 100km): ";
    cin >> mthnl;
    cout << "Nhap van toc trung binh(km/h): ";
    cin >> vttb;
    cin.ignore();
    cout << "Nhap diem den: ";
    getline(cin, dden);
    cout << "Nhap diem di: ";
    getline(cin, ddi);
    this->quangDuong = qd;
    this->thoiGianCho = tgc;
    this->mucTieuHaoNhienLieu = mthnl;
    this->vanTocTrungBinh = vttb;
    this->diemDen = dden;
    this->diemDi = ddi;
};

void XE_TAXI::xuatTTXeTaXi() {
    int phiCho = 0;
    int cuocPhi = 0;
    float chiPhiNhienLieu;
    cout << "Quang duong: " << this->quangDuong <<"km" << endl;
    cout << "Diem den: " << this->diemDen << endl;
    cout << "Diem di: " << this->diemDi << endl;
    
    if (this->thoiGianCho > 5)phiCho = 5000;
    else if (this->thoiGianCho > 10) {
        phiCho = 5000;
        for (int i = 11;i <= this->thoiGianCho;i++)phiCho += 3000;
    }

    if (this->quangDuong < 5) cuocPhi = 20000;
    else if (this->quangDuong >= 5 && this->quangDuong <= 10) cuocPhi = 15000;
    else cuocPhi = 13000;

    cout << "Gia cuoc chuyen di la: " << phiCho + cuocPhi * this->quangDuong<<" VND" << endl;
    chiPhiNhienLieu = this->mucTieuHaoNhienLieu / 100 * (float)this->quangDuong * 23000;
    cout << "Chi phi nhien lieu: " << chiPhiNhienLieu << " VND" << endl;
    cout << "Doanh thu: " << phiCho + cuocPhi * this->quangDuong - chiPhiNhienLieu <<" VND" << endl;// doanh thu = gia cuoc - phi nhien lieu

};


int main() {
    XE_TAI tai;
    XE_BUYT buyt;
    XE_TAXI taxi;
    int manHinh1, manHinh2;
    int checkBuyt = 0;
    int checkTaxi = 0;
    int checkTai = 0;
    menu:
    cout << "============ Quan ly xe =========" << endl;
    cout << endl;
    cout << "1. Xe buyt"<< endl ;
    cout << "2. Xe tai" << endl;
    cout << "3. Xe taXi"<< endl;
    cout << "4. Thoat chuong trinh" << endl;
    cin >> manHinh1;
    if (manHinh1 == 1) {
        system("cls");
        tryAgain:
        cout << "============= Quan ly xe ========" << endl;

        cout << "1. Nhap thong tin" << endl;

        cout << "2. Xuat thong tin" << endl;

        cout << "3. Tro ve menu truoc" << endl;
        cin >> manHinh2;

        if (manHinh2 == 1) {
            //buyt.tinhTGTrungBinhXeChayGiua2Tram();
            buyt.nhapTTXeBuyt(checkBuyt);
            cout << "Nhap giu lieu thanh cong!!" << endl;
            system("pause");
            system("cls");
            goto tryAgain;
        }
        else if (manHinh2 == 2) {
            if (checkBuyt != 0) {
                buyt.xuatTTXeBuyt();
                system("pause");
                system("cls");
                goto tryAgain;
            }
            else {
                cout << "Xin moi nhap thong tin xe Buyt truoc khi xuat!!" << endl;
                system("pause");
                system("cls");
                goto tryAgain;
            }
        }
        else if (manHinh2 == 3) {
            system("cls");
            goto menu;
        }
        else {

            cout << "Nhap sai xin moi nhap lai!!"<<endl;
            system("pause");
            system("cls");
            goto tryAgain;
        }
    }
    else if (manHinh1 == 2) {
        system("cls");
    tryAgain1:
        cout << "============= Quan ly xe ========" << endl;

        cout << "1. Nhap thong tin" << endl;

        cout << "2. Xuat thong tin" << endl;

        cout << "3. Tro ve menu truoc" << endl;
        cin >> manHinh2;

        if (manHinh2 == 1) {
            tai.nhapTTXeTai(checkTai);
            cout << "Nhap giu lieu thanh cong!!"<<endl;
            system("pause");
            system("cls");
            goto tryAgain1;
        }
        else if (manHinh2 == 2) {
            if (checkTai != 0) {
                tai.xuatTTXeTai();
                system("pause");
                system("cls");
                goto tryAgain1;
            }
            else {
                cout << "Xin moi nhap thong tin xe Tai truoc khi xuat!!" << endl;
                system("pause");
                system("cls");
                goto tryAgain1;
            }
        }
        else if (manHinh2 == 3) {
            system("cls");
            goto menu;
        }
        else {

            cout << "Nhap sai xin moi nhap lai!!" << endl;
            system("pause");
            system("cls");
            goto tryAgain1;
        }
    }
    else if (manHinh1 == 3) {
        system("cls");
    tryAgain2:
        cout << "============= Quan ly xe ========" << endl;

        cout << "1. Nhap thong tin" << endl;

        cout << "2. Xuat thong tin" << endl;

        cout << "3. Tro ve menu truoc" << endl;
        cin >> manHinh2;

        if (manHinh2 == 1) {
            taxi.nhapTTXeTaXi(checkTaxi);
            cout << "Nhap giu lieu thanh cong!!"<<endl;
            system("pause");
            system("cls");
            goto tryAgain2;
        }
        else if (manHinh2 == 2) {
            if (checkTaxi != 0) {
                taxi.xuatTTXeTaXi();
                system("pause");
                system("cls");
                goto tryAgain2;
            }
            else {
                cout << "Xin moi nhap thong tin xe Taxi truoc khi xuat!!" << endl;
                system("pause");
                system("cls");
                goto tryAgain2;
            }
        }
        else if (manHinh2 == 3) {
            system("cls");
            goto menu;
        }
        else {

            cout << "Nhap sai xin moi nhap lai!!" << endl;
            system("pause");
            system("cls");
            goto tryAgain2;
        }
    }
    else if (manHinh1 == 4) {
        
        system("cls");
        cout << " Chuong trinh ket thuc!!" << endl;
        system("pause");
        exit(0);
    }
    else {
        cout << "Nhap sai xin moi nhap lai!!" << endl;
        system("pause");
        system("cls");
        goto menu;

    }
}
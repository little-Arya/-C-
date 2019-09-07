#pragma once
#include"stdafx.h"
#include"Shape.h"
#include"Drawing01Doc.h"
#include"math.h"
#include"CShapeDlg.h"
IMPLEMENT_SERIAL(CSquare, CObject, 1)
CShape::CShape()
{
	
} // ape�ຯ������
void CSquare::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
	}
}

CShape::~CShape() {}

CSquare::CSquare()//���������޲κ�������
{
	Type = SQUARE;//ͼԪ����
	OrgX = 100;//ͼԪԭ������
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 25;//�߽���
	FillColor = RGB(0, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;//�����α߳�
}
CSquare::CSquare(int x, int y, int w)
{
	OrgX = x;//������
	OrgY = y;
	width = w;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 25;//�߽���
	FillColor = RGB(0, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
}
void CSquare::Draw(CDC*pDC)//����������
{
	CPen pen, *pOldPen;//�¡��ϻ���
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//�������ʣ����͡���ɫ����ȣ�
	pOldPen = (CPen*)pDC->SelectObject(&pen);//ѡ���»��ʲ������ϻ���
	CBrush brush, *pOldBrush;//���ϻ�ˢ
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//�������Ϊ�û��Զ����������
	else
		brush.CreateSolidBrush(FillColor); //�������ΪĬ�ϰ�ɫ�������
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);//����������

	pDC->SelectObject(pOldPen);//�ָ��ϻ��ʡ��ϻ�ˢ��
	pDC->SelectObject(pOldBrush);

}

bool CSquare::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX - width / 2) &&(pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) && (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}
void CSquare::SetValue(ElementType t, int x, int y, int w, int h)//���������ζ����еĲ������ݳ�Ա���뻭�ʺͻ�ˢ�޹صģ���ֵ
{
	Type = t; OrgX = x;OrgY = y;width = w;
}
void CSquare::GetValue(ElementType &t, int &x, int &y, int &w, int &h)//��ȡ�����ζ����в������ݳ�Ա��ֵ��ͨ�����ò�����ֵ����ʵ�ڲ���
{
	t = Type;x = OrgX;y = OrgY;w = width;h = 0;
}

IMPLEMENT_SERIAL(CRectangle, CObject, 2)//������CRectangleʵ�����л�
CRectangle::CRectangle() {
	Type = RECTANGLE;
	OrgX = 100;//ԭ������
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;
	height = 50;
}
//CRectangle::~CRectangle()



CRectangle::CRectangle(int x, int y, int w, int h)
{
	Type = RECTANGLE;
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = w; height = h;
}

void CRectangle::Draw(CDC*pDC)  //�����εĻ��ƺ���
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);
	else
		brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(OrgX - width / 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

}
bool CRectangle::IsMatched(CPoint pnt)//���ص�pnt�Ƿ�����ͼԪ��
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - height / 2) && (pnt.y <= OrgY + height / 2))
		return true;
	else
		return false;


}
void CRectangle::Serialize(CArchive& ar)//���л�������ͼԪ
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << height;
		ar << width;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar >> height;
		ar >> width;
	}


}


void CRectangle::SetValue(ElementType t, int x, int y, int w, int h)  //���ó����ζ����еĲ������ݳ�Ա���뻭�ʺͻ�ˢ�޹صģ���ֵ
{
	Type = t; OrgX = x;OrgY = y;width = w;height = h;
}
void CRectangle::GetValue(ElementType &t, int &x, int &y, int &w, int &h) //��ȡ�����ζ����в������ݳ�Ա��ֵ��ͨ�����ò�����ֵ����ʵ�ڲ���
{
	t = Type;x = OrgX;y = OrgY;w = width;h = height;
}

IMPLEMENT_SERIAL(CTriangle, CObject, 3)
CTriangle::CTriangle()
{
	Type = TRIANGLE;//ͼԪ����
	OrgX = 100;//ͼԪԭ������
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 25;//�߽���
	FillColor = RGB(0, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;//�����α߳�

}
CTriangle::CTriangle(int x, int y, int w)
{
	OrgX = x;//������
	OrgY = y;
	width = w;
	BorderColor = RGB(1, 1, 1);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 2;//�߽���
	FillColor = RGB(255, 255, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����

}
CTriangle:: ~CTriangle() {};

void CTriangle::Draw(CDC*pDC)//����������
{
	CPen pen, *pOldPen;//�¡��ϻ���
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//�������ʣ����͡���ɫ����ȣ�
	pOldPen = (CPen*)pDC->SelectObject(&pen);//ѡ���»��ʲ������ϻ���
	CBrush brush, *pOldBrush;//���ϻ�ˢ
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//�������Ϊ�û��Զ����������
	else
		brush.CreateSolidBrush(FillColor); //�������ΪĬ�ϰ�ɫ�������
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	int x1 = OrgX - width * 58 / 100;				//�����ε�������
	int y1 = OrgY + width / 3;
	int x2 = OrgX + 58 * width / 100;
	int y2 = OrgY + width / 3;
	int x3 = OrgX;
	int y3 = OrgY - width * 2 / 3;
	CPoint a[3] = { CPoint(x1, y1),  CPoint(x2, y2),  CPoint(x3 , y3) };
	pDC->Polygon(a, 3);
	pDC->SelectObject(pOldPen);//�ָ��ϻ��ʡ��ϻ�ˢ��
	pDC->SelectObject(pOldBrush);

}
void CTriangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}
bool CTriangle::IsMatched(CPoint pnt) {
	int x1 = OrgX - width * 58 / 100;				//�����ε�������
	int y1 = OrgY + width / 3;
	int x2 = OrgX + 58 * width / 100;
	int y2 = OrgY + width / 3;
	int x3 = OrgX;
	int y3 = OrgY - width * 2 / 3;

	int c1 = (pnt.x - x1)*(pnt.x - x1) + (pnt.y - y1)*(pnt.y - y1);
	int c2 = (pnt.x - x2)*(pnt.x - x2) + (pnt.y - y2)*(pnt.y - y2);
	int c3 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);
	int c4 = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);

	if (c1 + c2<c3 + c4)
		return true;
	else
		return false;
}

void CTriangle::SetValue(ElementType t, int x, int y, int w, int l)
{
	Type = t; OrgX = x;OrgY = y; width = w;length = l;
}
void CTriangle::GetValue(ElementType &t, int &x, int &y, int &w, int &l)
{
	t = Type;x = OrgX;y = OrgY;w = width;l = length;
}

IMPLEMENT_SERIAL(Circle, CObject, 4)
Circle::Circle()
{

	Type = CIRCLE;//ͼԪ����
	OrgX = 100;//ͼԪԭ������
	OrgY = 200;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 2;//�߽���
	FillColor = RGB(0, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	radius = 100;

}
Circle::Circle(int x, int y, int r)
{
	OrgX = x;//������
	OrgY = y;
	radius = r;
	BorderColor = RGB(1, 1, 1);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 2;//�߽���
	FillColor = RGB(255, 255, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
}
Circle::~Circle() {}

void Circle::Draw(CDC*pDC)//����Բ��
{
	CPen pen, *pOldPen;//�¡��ϻ���
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//�������ʣ����͡���ɫ����ȣ�
	pOldPen = (CPen*)pDC->SelectObject(&pen);//ѡ���»��ʲ������ϻ���
	CBrush brush, *pOldBrush;//���ϻ�ˢ
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//�������Ϊ�û��Զ����������
	else
		brush.CreateSolidBrush(FillColor); //�������ΪĬ�ϰ�ɫ�������
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - radius, OrgY + radius, OrgX + radius, OrgY - radius);//����Բ��
	pDC->SelectObject(pOldPen);//�ָ��ϻ��ʡ��ϻ�ˢ��
	pDC->SelectObject(pOldBrush);

}
void Circle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << radius;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar >> radius;
	}
}
bool Circle::IsMatched(CPoint pnt) {
	if (((pnt.x - OrgX) * (pnt.x - OrgX)) + ((pnt.y - OrgY) * (pnt.y - OrgY)) <= (radius*radius))
		return true;
	else
		return false;
}

void Circle::SetValue(ElementType t, int x, int y, int w, int l)
{
	Type = t; OrgX = x;OrgY = y; width = w;length = l;
}

void Circle::GetValue(ElementType &t, int &x, int &y, int &w, int &l)
{
	t = Type;x = OrgX;y = OrgY;w = width;l = length;
}





IMPLEMENT_SERIAL(CEllipse, CObject,5 )
CEllipse::CEllipse()
{
	Type = ELLIPSE;//ͼԪ����
	OrgX = 300;//ͼԪԭ������
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 2;//�߽���
	FillColor = RGB(255, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;//�����εĳ��Ϳ�
	length = 200;

}
CEllipse::CEllipse(int x, int y, int w, int l)
{
	OrgX = x;//������
	OrgY = y;
	width = w;
	length = l;
	BorderColor = RGB(1, 1, 1);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(255, 255, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
}
CEllipse::~CEllipse() {}

void CEllipse::Draw(CDC*pDC)//����Բ��
{
	CPen pen, *pOldPen;//�¡��ϻ���
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//�������ʣ����͡���ɫ����ȣ�
	pOldPen = (CPen*)pDC->SelectObject(&pen);//ѡ���»��ʲ������ϻ���
	CBrush brush, *pOldBrush;//���ϻ�ˢ
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//�������Ϊ�û��Զ����������
	else
		brush.CreateSolidBrush(FillColor); //�������ΪĬ�ϰ�ɫ�������
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - length, OrgY + width, OrgX + length, OrgY - width);//������Բ
	pDC->SelectObject(pOldPen);//�ָ��ϻ��ʡ��ϻ�ˢ��
	pDC->SelectObject(pOldBrush);

}
void CEllipse::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << length;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
		ar >> length;
	}
}
bool CEllipse::IsMatched(CPoint pnt) {
	if (((pnt.x - OrgX) * (pnt.x - OrgX)) + ((pnt.y - OrgY) * (pnt.y - OrgY)) <= (width*length))
		return true;
	else
		return false;
}

void CEllipse::SetValue(ElementType t, int x, int y, int w, int l)
{
	Type = t; OrgX = x;OrgY = y; width = w;length = l;
}
void CEllipse::GetValue(ElementType &t, int &x, int &y, int &w, int &l)
{
	t = Type;x = OrgX;y = OrgY;w = width;l = length;
}



IMPLEMENT_SERIAL(CText, CObject, 6)
CText::CText() 
{
	Type = TEXT;//ͼԪ����
	OrgX = 300;//ͼԪԭ������
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 2;//�߽���
	FillColor = RGB(255, 0, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	height = 25;
	angle = 45;
	CString text;

}
CText::CText(int x, int y, int h, int a, CString t)
{
	OrgX = x;//������
	OrgY = y;
	height = 30;
	angle = a;
	text = t;
	BorderColor = RGB(1, 1, 1);//�߽���ɫ
	BorderType = 0;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(255, 255, 255);//�����ɫ
	FillType = 1;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
}
CText::~CText() {}

void CText::Draw(CDC*pDC)//�����ı�
{
	CFont  *poldfont, *pnewfont;
	pnewfont = new CFont;
	pnewfont->CreateFont(
		height,						//���߼��߶�
		0,							//���߼����
		angle * 10,						//����ʸ����X��н�
		angle * 10,						//������X����н�
		1,							//�����ֵ
		0,							//�Ƿ�б��
		0,							//�Ƿ���»���
		0,							//�Ƿ���ɾ����
		ANSI_CHARSET,				//�ַ���
		OUT_DEFAULT_PRECIS,         // �ü�����
		CLIP_DEFAULT_PRECIS,        // �������
		DEFAULT_QUALITY,            // �����������
		DEFAULT_PITCH | FF_SWISS,   // �������������
		_T("Times New Roman")		//��������
	);
	poldfont = pDC->SelectObject(pnewfont);// //�ڽ��¶���ѡ���豸������ͬʱ����ָ��ǰһ�α�ѡ�����ָ�롣���ñ���ԭ���Ķ����Ա��������ʱ�ָ�����

	pDC->SetTextColor(BorderColor);
	pDC->SetBkColor(FillColor);
	pDC->TextOut(OrgX, OrgY, text);

	pDC->SelectObject(poldfont);//�ָ��ϻ���
	delete pnewfont;
}
void CText::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << height;
		ar << angle;
		ar << text;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar >> height;
		ar >> angle;
		ar >> text;
	}
}
bool CText::IsMatched(CPoint pnt) {
	if ((pnt.x >= OrgX - height) && (pnt.x <= OrgX + height) && (pnt.y >= OrgY - height) && (pnt.y <= OrgY + height))
		return true;
	else
		return false;
}

void CText::SetValue(ElementType t, int x, int y, int w, int l)
{
	Type = t; OrgX = x;OrgY = y; width = w;length = l;
}
void CText::GetValue(ElementType &t, int &x, int &y, int &w, int &l)
{
	t = Type;x = OrgX;y = OrgY;w = width;l = length;

}


void CText::SetText(int m_text)
{
}

void CText::GetText(int m_text)
{
}

void CShape::SetPen(COLORREF bcolor, int btype, int bwidth)
{
	
	BorderColor = bcolor;BorderType = btype; BorderWidth = bwidth;
}

void CShape::GetPen(COLORREF & bcolor, int & btype, int & bwidth)
{
	bcolor = BorderColor;btype = BorderType;bwidth = BorderWidth;
}

void CShape::SetBrush(COLORREF fcolor, int ftype)
{
	FillColor = fcolor;FillType = ftype;
}

void CShape::GetBrush(COLORREF & fcolor, int & ftype)
{
	fcolor = FillColor;ftype = FillType;
}

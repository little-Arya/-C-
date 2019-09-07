#pragma once
#include"stdafx.h"
#include"Shape.h"
#include"Drawing01Doc.h"
#include"math.h"
#include"CShapeDlg.h"
IMPLEMENT_SERIAL(CSquare, CObject, 1)
CShape::CShape()
{
	
} // ape类函数定义
void CSquare::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
	}
}

CShape::~CShape() {}

CSquare::CSquare()//正方形类无参函数定义
{
	Type = SQUARE;//图元类型
	OrgX = 100;//图元原点坐标
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 25;//边界宽度
	FillColor = RGB(0, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
	width = 100;//正方形边长
}
CSquare::CSquare(int x, int y, int w)
{
	OrgX = x;//点坐标
	OrgY = y;
	width = w;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 25;//边界宽度
	FillColor = RGB(0, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
}
void CSquare::Draw(CDC*pDC)//绘制正方形
{
	CPen pen, *pOldPen;//新、老画笔
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//创建画笔（类型、颜色、宽度）
	pOldPen = (CPen*)pDC->SelectObject(&pen);//选择新画笔并保存老画笔
	CBrush brush, *pOldBrush;//新老画刷
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//填充类型为用户自定义填充类型
	else
		brush.CreateSolidBrush(FillColor); //填充类型为默认白色填充类型
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);//绘制正方形

	pDC->SelectObject(pOldPen);//恢复老画笔、老画刷。
	pDC->SelectObject(pOldBrush);

}

bool CSquare::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX - width / 2) &&(pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) && (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}
void CSquare::SetValue(ElementType t, int x, int y, int w, int h)//设置正方形对象中的部分数据成员（与画笔和画刷无关的）的值
{
	Type = t; OrgX = x;OrgY = y;width = w;
}
void CSquare::GetValue(ElementType &t, int &x, int &y, int &w, int &h)//获取正方形对象中部分数据成员的值，通过引用参数将值传到实在参数
{
	t = Type;x = OrgX;y = OrgY;w = width;h = 0;
}

IMPLEMENT_SERIAL(CRectangle, CObject, 2)//声明类CRectangle实现序列化
CRectangle::CRectangle() {
	Type = RECTANGLE;
	OrgX = 100;//原点坐标
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 100;
	height = 50;
}
//CRectangle::~CRectangle()



CRectangle::CRectangle(int x, int y, int w, int h)
{
	Type = RECTANGLE;
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w; height = h;
}

void CRectangle::Draw(CDC*pDC)  //长方形的绘制函数
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
bool CRectangle::IsMatched(CPoint pnt)//重载点pnt是否落在图元内
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - height / 2) && (pnt.y <= OrgY + height / 2))
		return true;
	else
		return false;


}
void CRectangle::Serialize(CArchive& ar)//序列化长方形图元
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
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
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> height;
		ar >> width;
	}


}


void CRectangle::SetValue(ElementType t, int x, int y, int w, int h)  //设置长方形对象中的部分数据成员（与画笔和画刷无关的）的值
{
	Type = t; OrgX = x;OrgY = y;width = w;height = h;
}
void CRectangle::GetValue(ElementType &t, int &x, int &y, int &w, int &h) //获取长方形对象中部分数据成员的值，通过引用参数将值传到实在参数
{
	t = Type;x = OrgX;y = OrgY;w = width;h = height;
}

IMPLEMENT_SERIAL(CTriangle, CObject, 3)
CTriangle::CTriangle()
{
	Type = TRIANGLE;//图元类型
	OrgX = 100;//图元原点坐标
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 25;//边界宽度
	FillColor = RGB(0, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
	width = 100;//正方形边长

}
CTriangle::CTriangle(int x, int y, int w)
{
	OrgX = x;//点坐标
	OrgY = y;
	width = w;
	BorderColor = RGB(1, 1, 1);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 2;//边界宽度
	FillColor = RGB(255, 255, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等

}
CTriangle:: ~CTriangle() {};

void CTriangle::Draw(CDC*pDC)//绘制三角形
{
	CPen pen, *pOldPen;//新、老画笔
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//创建画笔（类型、颜色、宽度）
	pOldPen = (CPen*)pDC->SelectObject(&pen);//选择新画笔并保存老画笔
	CBrush brush, *pOldBrush;//新老画刷
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//填充类型为用户自定义填充类型
	else
		brush.CreateSolidBrush(FillColor); //填充类型为默认白色填充类型
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	int x1 = OrgX - width * 58 / 100;				//三角形的三个点
	int y1 = OrgY + width / 3;
	int x2 = OrgX + 58 * width / 100;
	int y2 = OrgY + width / 3;
	int x3 = OrgX;
	int y3 = OrgY - width * 2 / 3;
	CPoint a[3] = { CPoint(x1, y1),  CPoint(x2, y2),  CPoint(x3 , y3) };
	pDC->Polygon(a, 3);
	pDC->SelectObject(pOldPen);//恢复老画笔、老画刷。
	pDC->SelectObject(pOldBrush);

}
void CTriangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar >> width;
	}
}
bool CTriangle::IsMatched(CPoint pnt) {
	int x1 = OrgX - width * 58 / 100;				//三角形的三个点
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

	Type = CIRCLE;//图元类型
	OrgX = 100;//图元原点坐标
	OrgY = 200;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 2;//边界宽度
	FillColor = RGB(0, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
	radius = 100;

}
Circle::Circle(int x, int y, int r)
{
	OrgX = x;//点坐标
	OrgY = y;
	radius = r;
	BorderColor = RGB(1, 1, 1);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 2;//边界宽度
	FillColor = RGB(255, 255, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
}
Circle::~Circle() {}

void Circle::Draw(CDC*pDC)//绘制圆形
{
	CPen pen, *pOldPen;//新、老画笔
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//创建画笔（类型、颜色、宽度）
	pOldPen = (CPen*)pDC->SelectObject(&pen);//选择新画笔并保存老画笔
	CBrush brush, *pOldBrush;//新老画刷
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//填充类型为用户自定义填充类型
	else
		brush.CreateSolidBrush(FillColor); //填充类型为默认白色填充类型
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - radius, OrgY + radius, OrgX + radius, OrgY - radius);//绘制圆形
	pDC->SelectObject(pOldPen);//恢复老画笔、老画刷。
	pDC->SelectObject(pOldBrush);

}
void Circle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << radius;

	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
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
	Type = ELLIPSE;//图元类型
	OrgX = 300;//图元原点坐标
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 2;//边界宽度
	FillColor = RGB(255, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
	width = 100;//长方形的长和宽
	length = 200;

}
CEllipse::CEllipse(int x, int y, int w, int l)
{
	OrgX = x;//点坐标
	OrgY = y;
	width = w;
	length = l;
	BorderColor = RGB(1, 1, 1);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(255, 255, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
}
CEllipse::~CEllipse() {}

void CEllipse::Draw(CDC*pDC)//绘制圆形
{
	CPen pen, *pOldPen;//新、老画笔
	pen.CreatePen(BorderType, BorderWidth, BorderColor);//创建画笔（类型、颜色、宽度）
	pOldPen = (CPen*)pDC->SelectObject(&pen);//选择新画笔并保存老画笔
	CBrush brush, *pOldBrush;//新老画刷
	if (FillType >= HS_HORIZONTAL && FillType <= HS_DIAGCROSS)
		brush.CreateHatchBrush(FillType, FillColor);//填充类型为用户自定义填充类型
	else
		brush.CreateSolidBrush(FillColor); //填充类型为默认白色填充类型
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(OrgX - length, OrgY + width, OrgX + length, OrgY - width);//绘制椭圆
	pDC->SelectObject(pOldPen);//恢复老画笔、老画刷。
	pDC->SelectObject(pOldBrush);

}
void CEllipse::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
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
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
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
	Type = TEXT;//图元类型
	OrgX = 300;//图元原点坐标
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 2;//边界宽度
	FillColor = RGB(255, 0, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
	height = 25;
	angle = 45;
	CString text;

}
CText::CText(int x, int y, int h, int a, CString t)
{
	OrgX = x;//点坐标
	OrgY = y;
	height = 30;
	angle = a;
	text = t;
	BorderColor = RGB(1, 1, 1);//边界颜色
	BorderType = 0;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(255, 255, 255);//填充颜色
	FillType = 1;//填充类型--实心、双对角、十字交叉等
}
CText::~CText() {}

void CText::Draw(CDC*pDC)//绘制文本
{
	CFont  *poldfont, *pnewfont;
	pnewfont = new CFont;
	pnewfont->CreateFont(
		height,						//字逻辑高度
		0,							//字逻辑宽度
		angle * 10,						//出口矢量与X轴夹角
		angle * 10,						//基线与X轴轴夹角
		1,							//字体磅值
		0,							//是否斜体
		0,							//是否带下划线
		0,							//是否有删除线
		ANSI_CHARSET,				//字符集
		OUT_DEFAULT_PRECIS,         // 裁剪精度
		CLIP_DEFAULT_PRECIS,        // 输出质量
		DEFAULT_QUALITY,            // 调距和字体族
		DEFAULT_PITCH | FF_SWISS,   // 字体的字样名字
		_T("Times New Roman")		//字体名称
	);
	poldfont = pDC->SelectObject(pnewfont);// //在将新对象选进设备环境的同时返回指向前一次被选对象的指针。作用保存原来的对象，以便完成任务时恢复它。

	pDC->SetTextColor(BorderColor);
	pDC->SetBkColor(FillColor);
	pDC->TextOut(OrgX, OrgY, text);

	pDC->SelectObject(poldfont);//恢复老画笔
	delete pnewfont;
}
void CText::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
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
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
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

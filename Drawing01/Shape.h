#pragma once
enum ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//����ͼԪ
	virtual bool IsMatched(CPoint pnt) = 0;//���Ƿ�����ͼ���ڲ�
	virtual void Serialize(CArchive& ar) = 0;
	virtual void SetValue(ElementType t, int x, int y, int width, int height) = 0;//�������ݳ�Աvirtual void GetValue(ElementType &t,int &x,int &y,int &width,int &height)=0;//��ȡ���ݳ�Ա��ֵ
	void SetPen(COLORREF bcolor, int btype, int bwidth);
	void GetPen(COLORREF &bcolor, int &btype, int &bwidth);
	void SetBrush(COLORREF fcolor, int ftype);
	void GetBrush(COLORREF &fcolor, int &ftype);
	virtual void GetValue(ElementType &t, int &x, int &y, int &width, int &height) = 0;//��ȡ���ݳ�Ա��ֵ
protected:
	ElementType Type;//ͼԪ����
	int OrgX;//ԭ������
	int OrgY;
	COLORREF   BorderColor;//�߽���ɫ
	int BorderType;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	int BorderWidth;//�߽���
	COLORREF  FillColor;//�����ɫ
	int FillType;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
};

class CSquare : public CShape//��������CSquare
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC*pDC);//����������
    bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	void SetValue(ElementType t, int x, int y, int width, int height);
	
	void GetValue(ElementType &t, int &x, int &y, int &width, int &height);
	
private:
	int width;//�߳�
    DECLARE_SERIAL(CSquare)//������CSquare֧�����л�
	
};

class CRectangle : public CShape
{
public:
	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	virtual void SetValue(ElementType t, int x, int y, int width, int height);//���ó����ζ����еĲ������ݳ�Ա���뻭�ʺͻ�ˢ�޹صģ���ֵ
	virtual void GetValue(ElementType &t, int &x, int &y, int &width, int &height);
	

private:
	int width;
	int height;
	COLORREF   BorderColor;//�߽���ɫ
	int BorderType;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	int BorderWidth;//�߽���
	COLORREF  FillColor;//�����ɫ
	int FillType;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ���
	DECLARE_SERIAL(CRectangle)//������CSquare֧�����л�
};

class CTriangle : public CShape//��������CSquare
{
public:
	CTriangle();
	CTriangle(int x, int y, int w);
	void Draw(CDC*pDC);//����������
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�������ͼԪ
	~CTriangle();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	


private:
	int width;//
	int length;
	DECLARE_SERIAL(CTriangle)//������CTriangle֧�����л�
};

class Circle : public CShape//Բ����
{
public:
	Circle();
	Circle(int x, int y, int r);
	void Draw(CDC*pDC);//����Բ��
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л�Բ��ͼԪ
	~Circle();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	

private:
	int radius;//�뾶
	int width;
	int length;
	
	DECLARE_SERIAL(Circle)//������Circle֧�����л�
};

class CEllipse : public CShape//��Բ��
{
public:
	CEllipse();
	CEllipse(int x, int y, int w, int l);
	void Draw(CDC*pDC);//������Բ��
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л���Բ��ͼԪ
	~CEllipse();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	
private:
	int width;//���Ϳ�
	int length;

	DECLARE_SERIAL(CEllipse)//������CSquare֧�����л�
};

class CText : public CShape//�ı���
{
public:
	CText();
	CText(int x, int y, int h, int a, CString t);
	void Draw(CDC*pDC);//�����ı�
	bool IsMatched(CPoint pnt);//���ص�pnt�Ƿ�����ͼԪ��
	virtual void Serialize(CArchive& ar);//���л��ı�ͼԪ
	~CText();
	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	
	void SetText(int m_text);
	void GetText(int m_text);
private:
	int height;//
	int angle;
	CString text;
	int width;
	int length;
	
	DECLARE_SERIAL(CText)//������CText֧�����л�
};
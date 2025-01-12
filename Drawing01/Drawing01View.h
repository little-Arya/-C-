
// Drawing01View.h: CDrawing01View 类的接口
//

#pragma once
#include"CShapeDlg.h"
#include"Drawing01Doc.h"
class CDrawing01View : public CScrollView
{
protected: // 仅从序列化创建
	CDrawing01View();
	DECLARE_DYNCREATE(CDrawing01View)

// 特性
public:
	CDrawing01Doc * GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawing01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnRButtonDBlClK(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSquare();
	//afx_msg void OnRectangle();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	afx_msg void OnCircle();
	afx_msg void OnTriangle();
	afx_msg void OnEllipse();
	afx_msg void OnText();
};

#ifndef _DEBUG  // Drawing01View.cpp 中的调试版本
inline CDrawing01Doc* CDrawing01View::GetDocument() const
   { return reinterpret_cast<CDrawing01Doc*>(m_pDocument); }
#endif


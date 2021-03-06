//  MIT License
//
//  Copyright (c) 2019 Ruhr-University Bochum, Germany, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2019 Marc Fyrbiak, Sebastian Wallat, Max Hoffmann ("ORIGINAL AUTHORS"). All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#pragma once

#include <QFrame>

class QHBoxLayout;
class QLabel;

namespace hal
{
    class ExpandingListWidget;


    class ExpandingListButton : public QFrame
    {
        Q_OBJECT
        Q_PROPERTY(bool hover READ hover)
        Q_PROPERTY(bool selected READ selected)
        Q_PROPERTY(QString type READ type)
        Q_PROPERTY(QString iconStyle READ iconStyle WRITE setIconStyle)

    public:
        ExpandingListButton(QWidget* parent = 0);

        void enterEvent(QEvent* event) Q_DECL_OVERRIDE;
        void leaveEvent(QEvent* event) Q_DECL_OVERRIDE;
        void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

        bool hover();
        bool selected();
        QString type();
        QString iconStyle();

        void setSelected(bool selected);
        void set_type(const QString& type);
        void setIconStyle(const QString& style);

        void setIconPath(const QString& path);
        void setText(const QString& text);

        void repolish();

    Q_SIGNALS:
        void clicked();

    private:
        QHBoxLayout* mLayout;
        QFrame* mLeftBorder;
        QLabel* mIconLabel;
        QLabel* mTextLabel;
        QFrame* mRightBorder;

        bool mHover;
        bool mSelected;
        QString mType;
        QString mIconStyle;
        QString mIconPath;
    };
}

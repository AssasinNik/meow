#include "profil.h"
#include "ui_profil.h"
#include <QFileDialog>
#include <QPainter>
#include <QPainterPath>

profil::profil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profil)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Создание PhotoLabel для отображения фотографии
    photoLabel = new PhotoLabel(this);
    photoLabel->setFixedSize(200, 200);
    photoLabel->setStyleSheet("border-radius: 100px; border: 2px solid #6D55FF;");
    photoLabel->setAlignment(Qt::AlignCenter);

    // Создание QLabel для затемняющего слоя
    overlayLabel = new QLabel(this);
    overlayLabel->setFixedSize(200, 200);
    overlayLabel->setStyleSheet("background-color: rgba(0, 0, 0); border-radius: 100px;");
    overlayLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Прозрачность для событий мыши
    overlayLabel->hide();

    // Создание QLabel для отображения текста
    textLabel = new QLabel("Выбрать фото", this);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("color: black; font-size: 18px;");
    textLabel->setFixedSize(200, 200);
    textLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Прозрачность для событий мыши
    textLabel->hide();

    // Установка начальной фотографии
    QPixmap defaultPhoto(":/default-photo.jpg");
    updatePhotoLabel(defaultPhoto);

    // Размещение overlayLabel и textLabel поверх photoLabel
    overlayLabel->move(photoLabel->pos());
    textLabel->move(photoLabel->pos());

    connect(photoLabel, &PhotoLabel::clicked, this, &profil::changePhoto);
    photoLabel->installEventFilter(this);
}

profil::~profil()
{
    delete ui;
}

void profil::mousePressEvent(QMouseEvent *event)
{
    // Запомнить начальную позицию при нажатии на кнопку мыши
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void profil::mouseMoveEvent(QMouseEvent *event)
{
    // Перемещать окно при зажатой левой кнопке мыши
    if (event->buttons() & Qt::LeftButton && m_dragging) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void profil::mouseReleaseEvent(QMouseEvent *event)
{
    // Остановить перемещение окна при отпускании кнопки мыши
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();
    }
}

void profil::changePhoto()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выбрать фотографию"), "", tr("Images (*.png *.xpm *.jpg)"));
    if (!fileName.isEmpty()) {
        QPixmap newPhoto(fileName);
        updatePhotoLabel(newPhoto);
    }
}

void profil::updatePhotoLabel(const QPixmap &pixmap)
{
    QPixmap scaledPixmap = pixmap.scaled(photoLabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QPixmap roundedPixmap(photoLabel->size());
    roundedPixmap.fill(Qt::transparent);

    QPainter painter(&roundedPixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(0, 0, photoLabel->width(), photoLabel->height());
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, scaledPixmap);

    photoLabel->setPixmap(roundedPixmap);
}

bool profil::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == photoLabel) {
        if (event->type() == QEvent::Enter) {
            overlayLabel->show(); // Показать затемняющий слой
            textLabel->show();    // Показать текст
        } else if (event->type() == QEvent::Leave) {
            overlayLabel->hide(); // Скрыть затемняющий слой
            textLabel->hide();    // Скрыть текст
        }
    }
    return QWidget::eventFilter(obj, event);
}

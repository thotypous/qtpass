#ifndef USERSDIALOG_H_
#define USERSDIALOG_H_

#include <QCloseEvent>
#include <QDateTime>
#include <QDialog>
#include <QList>
#include <QStandardItemModel>

namespace Ui {
class UsersDialog;
}

class QListWidgetItem;

/*!
    \struct UserInfo
    \brief Stores key info lines including validity, creation date and more.
 */
struct UserInfo {
  UserInfo() : validity('-'), have_secret(false), enabled(false) {}

  QString name;
  QString key_id;
  char validity;
  bool have_secret;
  bool enabled;
  QDateTime expiry;
  QDateTime created;
};


/*!
    \class UsersDialog
    \brief Handles listing and editing of GPG users.

    Selection of whom to encrypt to.
 */
class UsersDialog : public QDialog {
  Q_OBJECT

public:
  explicit UsersDialog(QWidget *parent = 0);
  ~UsersDialog();
  void setUsers(QList<UserInfo> *);

protected:
  void closeEvent(QCloseEvent *event);
  void keyPressEvent(QKeyEvent *event);

private slots:
  void itemChange(QListWidgetItem *item);
  void on_lineEdit_textChanged(const QString &filter);
  void on_checkBox_clicked();

private:
  Ui::UsersDialog *ui;
  QList<UserInfo> *userList;
  void populateList(const QString &filter);
};

#endif // USERSDIALOG_H_

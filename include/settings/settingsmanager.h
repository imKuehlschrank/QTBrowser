#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QSettings>

enum class SETTING {
    DOWNLOAD_PATH,
    USER_CERTIFICATE_PATH,
    USER_KEY_PATH
};

class SettingsManager
{
public:
    static SettingsManager& getInstance();
    void writeSettings(SETTING s, QString value);
    QString getSetting(SETTING s);
    void printAllSettings();

private:
    SettingsManager(){}
    static SettingsManager* instance_;

    const QMap<SETTING, QString>map = [](){
            QMap<SETTING, QString> m;
            m.insert(SETTING::DOWNLOAD_PATH,         "download_path");
            m.insert(SETTING::USER_CERTIFICATE_PATH, "user_certificate_path");
            m.insert(SETTING::USER_KEY_PATH,         "user_key_path" );

            return m;
    }();


    const QString settings_file_path = "data/settings.ini";
};

#endif // SETTINGSMANAGER_H

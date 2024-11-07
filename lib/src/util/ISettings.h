//
// Created by Yoo Cherry on 09.10.24.
//

#ifndef ISETTINGS_H
#define ISETTINGS_H

class ISettings {
 public:
  virtual ~ISettings() = default;

  virtual void load() = 0;

  virtual void save() = 0;
};
#endif //ISETTINGS_H

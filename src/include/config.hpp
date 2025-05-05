#ifndef PAM_OAUTH2_DEVICE_CONFIG_HPP
#define PAM_OAUTH2_DEVICE_CONFIG_HPP

#include <map>
#include <set>
#include <string>

class Config {
 public:
  void load(const char *path);
  std::string client_id, client_secret, scope, device_endpoint, token_endpoint,
      userinfo_endpoint, username_attribute;
  bool require_mfa, qr_show;
  int qr_error_correction_level;
};

#endif  // PAM_OAUTH2_DEVICE_CONFIG_HPP

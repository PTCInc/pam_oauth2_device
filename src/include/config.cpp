#include "config.hpp"

#include <fstream>
#include <set>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Config::load(const char *path) {
  std::ifstream config_fstream(path);
  json j;
  config_fstream >> j;

  client_id = j.at("oauth").at("client").at("id").get<std::string>();
  client_secret = j.at("oauth").at("client").at("secret").get<std::string>();
  scope = j.at("oauth").at("scope").get<std::string>();
  device_endpoint = j.at("oauth").at("device_endpoint").get<std::string>();
  token_endpoint = j.at("oauth").at("token_endpoint").get<std::string>();
  userinfo_endpoint = j.at("oauth").at("userinfo_endpoint").get<std::string>();
  username_attribute =
      j.at("oauth").at("username_attribute").get<std::string>();
  require_mfa = j["oauth"].contains("require_mfa")
                    ? j.at("oauth").at("require_mfa").get<bool>()
                    : false;
  qr_error_correction_level =
      j.at("qr").at("error_correction_level").get<int>();
  qr_show =
      (j["qr"].contains("show")) ? j.at("qr").at("show").get<bool>() : true;
}

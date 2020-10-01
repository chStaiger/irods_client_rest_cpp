
#include "irods_rest_api_base.h"
#include "generalAdmin.h"

// this is contractually tied directly to the swagger api definition, and the below implementation
#define MACRO_IRODS_ADMIN_API_IMPLEMENTATION \
    Pistache::Http::Code code; \
    std::string message; \
    std::tie(code, message) = irods_admin_(headers.getRaw("Authorization").value(), action.get(), target.get(), arg2.get(), arg3.get(), arg4.get(), arg5.get(), arg6.get(), arg7.get()); \
    response.headers().add<Pistache::Http::Header::AccessControlAllowOrigin>("*"); \
    response.send(code, message);

namespace irods {
namespace rest {
class admin : api_base {
    public:
    std::tuple<Pistache::Http::Code &&, std::string> operator()(
        const std::string& _auth_header,
        const std::string& _action,
        const std::string& _target,
        const std::string& _arg2,
        const std::string& _arg3,
        const std::string& _arg4,
        const std::string& _arg5,
        const std::string& _arg6,
        const std::string& _arg7)
    {

        auto conn = get_connection(_auth_header);

        try {
            auto gen_inp = generalAdminInp_t{
                               _action == "remove" ? "rm" : _action.c_str(),
                               _target.c_str(),
                               _arg2.c_str(),
                               _arg3.c_str(),
                               _arg4.c_str(),
                               _arg5.c_str(),
                               _arg6.c_str(),
                               _arg7.c_str(),
                               nullptr,
                               nullptr};
            auto err = rcGeneralAdmin(conn(), &gen_inp);
            if(err < 0) {
                auto error_name = std::string{rodsErrorName(err, nullptr)};
                return std::forward_as_tuple(
                        Pistache::Http::Code::Bad_Request,
                        error_name);
            }

            std::string results{"Success"};
            return std::forward_as_tuple(
                    Pistache::Http::Code::Ok,
                    results);
        }
        catch(const irods::exception& _e) {
            return std::forward_as_tuple(
                    Pistache::Http::Code::Bad_Request,
                    _e.what());
        }
    } // operator()
}; // class admin
}; // namespace rest
}; // namespace irods
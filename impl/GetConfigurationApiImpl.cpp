/**
* iRODS REST API
* This is the iRODS REST API
*
* OpenAPI spec version: 1.0.0
* Contact: info@irods.org
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/

#include "GetConfigurationApiImpl.h"

#include "utils.hpp"

namespace io::swagger::server::api
{
    using namespace io::swagger::server::model;

    GetConfigurationApiImpl::GetConfigurationApiImpl(Pistache::Address addr)
        : GetConfigurationApi(addr)
        , irods_get_configuration_{}
    {
    }

    void GetConfigurationApiImpl::handler_impl(const Pistache::Rest::Request& request,
                                               Pistache::Http::ResponseWriter& response)
    {
        irods::rest::handle_request(irods_get_configuration_, request, response);
    }
} // namespace io::swagger::server::api

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

#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#include "StreamGetApiImpl.h"

using namespace io::swagger::server::api;

int main() {
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8083));

    StreamGetApiImpl server(addr);
    server.init(2);
    server.start();

    server.shutdown();
}


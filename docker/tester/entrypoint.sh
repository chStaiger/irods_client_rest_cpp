#! /bin/bash -ex

stat ${local_package}

apt-get update && \
    (dpkg -i ${local_package} || true) && \
    apt-get install -fy --allow-downgrades && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/*

/etc/init.d/postgresql start

su - postgres -c 'psql -f /db_commands.txt'

python3 /var/lib/irods/scripts/setup_irods.py < /var/lib/irods/packaging/localhost_setup_postgres.input

/etc/init.d/irods_client_rest_cpp start

# TODO: Should this be the CMD rather than part of the ENTRYPOINT?
su - irods -c "python3 /var/lib/irods/scripts/run_tests.py --run_s test_irods_client_rest_cpp --topology_test icat --hostnames localhost tester_nginx-reverse-proxy_1 none none"
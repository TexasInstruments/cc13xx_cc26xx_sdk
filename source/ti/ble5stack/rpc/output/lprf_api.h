/*
 * Generated by erpcgen 1.7.4 on Thu Jun  3 17:44:56 2021.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_lprf_api_h_)
#define _lprf_api_h_

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
#pragma anon_unions
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"
#include "mesh_erpc_wrapper.h"
#include "zephyr/types.h"
#include "bluetooth/mesh/main.h"

#if 10704 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS)
#define ERPC_TYPE_DEFINITIONS

#endif // ERPC_TYPE_DEFINITIONS

/*! @brief BLEmesh_api identifiers */
enum _BLEmesh_api_ids
{
    kBLEmesh_api_service_id = 3,
    kBLEmesh_api_mesh_init_id = 1,
    kBLEmesh_api_bt_mesh_init_prov_raw_init_id = 2,
    kBLEmesh_api_bt_mesh_init_comp_raw_init_id = 3,
    kBLEmesh_api_bt_mesh_init_elem_raw_init_id = 4,
    kBLEmesh_api_bt_mesh_cfg_cli_raw_init_id = 5,
    kBLEmesh_api_bt_mesh_init_model_raw_init_id = 6,
    kBLEmesh_api_bt_mesh_cfg_srv_raw_init_id = 7,
    kBLEmesh_api_bt_mesh_health_srv_raw_init_id = 8,
    kBLEmesh_api_bt_mesh_reset_id = 9,
    kBLEmesh_api_bt_mesh_suspend_id = 10,
    kBLEmesh_api_bt_mesh_resume_id = 11,
    kBLEmesh_api_bt_mesh_iv_update_test_id = 12,
    kBLEmesh_api_bt_mesh_iv_update_id = 13,
    kBLEmesh_api_bt_mesh_lpn_set_id = 14,
    kBLEmesh_api_bt_mesh_lpn_poll_id = 15,
    kBLEmesh_api_bt_mesh_input_string_id = 16,
    kBLEmesh_api_bt_mesh_input_number_id = 17,
    kBLEmesh_api_bt_mesh_prov_enable_wrapper_id = 18,
    kBLEmesh_api_bt_mesh_prov_disable_wrapper_id = 19,
    kBLEmesh_api_bt_mesh_provision_id = 20,
    kBLEmesh_api_bt_mesh_cfg_app_key_add_wrapper_id = 21,
    kBLEmesh_api_bt_mesh_cfg_mod_app_bind_vnd_wrapper_id = 22,
    kBLEmesh_api_bt_mesh_cfg_mod_app_bind_wrapper_id = 23,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_add_vnd_wrapper_id = 24,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_add_wrapper_id = 25,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_del_wrapper_id = 26,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_del_vnd_wrapper_id = 27,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_va_add_wrapper_id = 28,
    kBLEmesh_api_bt_mesh_cfg_mod_sub_va_add_vnd_wrapper_id = 29,
    kBLEmesh_api_bt_mesh_cfg_mod_pub_set_wrapper_id = 30,
    kBLEmesh_api_bt_mesh_cfg_mod_pub_set_vnd_wrapper_id = 31,
    kBLEmesh_api_bt_mesh_is_provisioned_id = 32,
    kBLEmesh_api_bt_mesh_proxy_identity_enable_id = 33,
    kBLEmesh_api_bt_mesh_model_publish_wrapper_id = 34,
    kBLEmesh_api_bt_mesh_model_send_data_wrapper_id = 35,
    kBLEmesh_api_bt_mesh_model_find_wrapper_id = 36,
    kBLEmesh_api_bt_mesh_model_find_vnd_wrapper_id = 37,
    kBLEmesh_api_bt_mesh_model_extend_wrapper_id = 38,
    kBLEmesh_api_bt_mesh_fault_update_wrapper_id = 39,
    kBLEmesh_api_settings_load_wrapper_id = 40,
    kBLEmesh_api_store_data_wrapper_id = 41,
};

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif // _lprf_api_h_

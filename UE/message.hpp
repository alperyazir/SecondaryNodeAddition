#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

enum MESSAGE_TYPE{SgNBAdditionalRequest_t,SgNBAdditionalRequestAcknowledge_t,SgNBReconfigurationComplete_t,RRCConnectionReconfiguration_t,RRCConnectionReconfigurationComplete_t};
// SgNBAdditionalRequest message
struct PDCP_not_present_in_SN {
    QString Requested_SCG_E_RAB_Level_QoS_Parameters{"dummy"};
    QString MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP{"dummy"};
    QString Secondary_MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP{"dummy"};
    QString RLC_Mode{"dummy"};
    QString UL_Configuration{"dummy"};
    QString UL_PDCP_SN_Length{"dummy"};
    QString DL_PDCP_SN_Length{"dummy"};
    QString Duplication_activation{"dummy"};

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Requested_SCG_E_RAB_Level_QoS_Parameters"] = Requested_SCG_E_RAB_Level_QoS_Parameters;
        obj["MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP"] = MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP;
        obj["Secondary_MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP"] = Secondary_MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP;
        obj["RLC_Mode"] = RLC_Mode;
        obj["UL_Configuration"] = UL_Configuration;
        obj["UL_PDCP_SN_Length"] = UL_PDCP_SN_Length;
        obj["DL_PDCP_SN_Length"] = DL_PDCP_SN_Length;
        obj["Duplication_activation"] = Duplication_activation;
        return obj;
    }

};
struct PDCP_present_in_SN {
    QString Full_E_RAB_Level_QoS_Parameters{"dummy"};
    QString Maximum_MCG_admittable_E_RAB_Level_QoS_Parameters{"dummy"};
    QString DL_Forwarding{"dummy"};
    QString MeNB_DL_GTP_Tunnel_Endpoint_at_MCG{"dummy"};
    QString S1_UL_GTP_Tunnel_Endpoint{"dummy"};
    QString RLC_Mode{"dummy"};
    QString Bearer_Type{"dummy"};

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Full_E_RAB_Level_QoS_Parameters"] = Full_E_RAB_Level_QoS_Parameters;
        obj["Maximum_MCG_admittable_E_RAB_Level_QoS_Parameters"] = Maximum_MCG_admittable_E_RAB_Level_QoS_Parameters;
        obj["DL_Forwarding"] = DL_Forwarding;
        obj["MeNB_DL_GTP_Tunnel_Endpoint_at_MCG"] = MeNB_DL_GTP_Tunnel_Endpoint_at_MCG;
        obj["S1_UL_GTP_Tunnel_Endpoint"] = S1_UL_GTP_Tunnel_Endpoint;
        obj["RLC_Mode"] = RLC_Mode;
        obj["Bearer_Type"] = Bearer_Type;
        return obj;
    }

};
struct E_RAB_Request {
    QString E_RAB_ID{"dummy"};
    QString DRB_ID{"dummy"};
    QString EN_DC_Resource_Configuration{"dummy"};
    QString CHOICE_Resource_Configuration{"dummy"};
    PDCP_present_in_SN pdcp_present_in_sn;
    PDCP_not_present_in_SN pdcp_not_present_in_sn;

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["E_RAB_ID"] = E_RAB_ID;
        obj["DRB_ID"] = DRB_ID;
        obj["EN_DC_Resource_Configuration"] = EN_DC_Resource_Configuration;
        obj["CHOICE_Resource_Configuration"] = CHOICE_Resource_Configuration;
        obj["PDCP_present_in_SN"] = pdcp_present_in_sn.toJson();
        obj["PDCP_not_present_in_SN"] = pdcp_not_present_in_sn.toJson();
        return obj;
    }
};
struct SgNBAdditionalRequest {
    QString Message_Type{"dummy"};
    QString MeNB_UE_X2AP_ID{"dummy"};
    QString NR_UE_Security_Capabilities{"dummy"};
    QString SgNB_Security_Key{"dummy"};
    QString SgNB_UE_Aggregate_Maximum_Bit_Rate{"dummy"};
    QString Selected_PLMN{"dummy"};
    QString Handover_Restriction_List{"dummy"};
    E_RAB_Request e_rab_request;
    QString MeNB_to_SgNB_Container{"dummy"};
    QString SgNB_UE_X2AP_ID{"dummy"};
    QString Expected_UE_Behaviour{"dummy"};
    QString MeNB_UEU_X2AP_ID_Extension{"dummy"};
    QString Requested_split_SRBs{"dummy"};
    QString MeNB_Resource_Coordination_Information{"dummy"};
    QString SGNB_Addition_Trigger_Indication{"dummy"};
    QString Subscriber_Profile_ID_for_RAT_Frequency_priority{"dummy"};
    QString MeNB_Cell_ID{"dummy"};
    QString Desired_Activity_Notification_Level{"dummy"};
    QString Trace_Activation{"dummy"};
    QString Location_Information_at_SgNB_reporting{"dummy"};
    QString Masked_IMEISV{"dummy"};

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Message_Type"] = Message_Type;
        obj["MeNB_UE_X2AP_ID"] = MeNB_UE_X2AP_ID;
        obj["NR_UE_Security_Capabilities"] = NR_UE_Security_Capabilities;
        obj["SgNB_Security_Key"] = SgNB_Security_Key;
        obj["SgNB_UE_Aggregate_Maximum_Bit_Rate"] = SgNB_UE_Aggregate_Maximum_Bit_Rate;
        obj["Selected_PLMN"] = Selected_PLMN;
        obj["Handover_Restriction_List"] = Handover_Restriction_List;
        obj["E_RAB_Request"] = e_rab_request.toJson();
        obj["MeNB_to_SgNB_Container"] = MeNB_to_SgNB_Container;
        obj["SgNB_UE_X2AP_ID"] = SgNB_UE_X2AP_ID;
        obj["Expected_UE_Behaviour"] = Expected_UE_Behaviour;
        obj["MeNB_UEU_X2AP_ID_Extension"] = MeNB_UEU_X2AP_ID_Extension;
        obj["Requested_split_SRBs"] = Requested_split_SRBs;
        obj["MeNB_Resource_Coordination_Information"] = MeNB_Resource_Coordination_Information;
        obj["SGNB_Addition_Trigger_Indication"] = SGNB_Addition_Trigger_Indication;
        obj["Subscriber_Profile_ID_for_RAT_Frequency_priority"] = Subscriber_Profile_ID_for_RAT_Frequency_priority;
        obj["MeNB_Cell_ID"] = MeNB_Cell_ID;
        obj["Desired_Activity_Notification_Level"] = Desired_Activity_Notification_Level;
        obj["Trace_Activation"] = Trace_Activation;
        obj["Location_Information_at_SgNB_reporting"] = Location_Information_at_SgNB_reporting;
        obj["Masked_IMEISV"] = Masked_IMEISV;

        return obj;
    }


};


// SgNBAdditionalRequestAcknowledge message
struct PDCP_not_present_in_SN_Acknowledge {
    QString SgNB_DL_GTP_Tunnel_Endpoint_at_SCG{"dummy"};
    QString Secondary_SgNB_DL_GTP_Tunnel_Endpoint_at_SCG{"dummy"};
    QString LCID{"dummy"};

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["SgNB_DL_GTP_Tunnel_Endpoint_at_SCG"] = SgNB_DL_GTP_Tunnel_Endpoint_at_SCG;
        obj["Secondary_SgNB_DL_GTP_Tunnel_Endpoint_at_SCG"] = Secondary_SgNB_DL_GTP_Tunnel_Endpoint_at_SCG;
        obj["LCID"] = LCID;
        return obj;
    }
};
struct PDCP_present_in_SN_Acknowledge {
    QString S1_DL_GTP_Tunnel_Endpoint_at_the_SgNB{"dummy"};
    QString SgNB_UL_GTP_Tunnel_Endpoint_at_PDCP{"dummy"};
    QString RLC_Mode{"dummy"};
    QString DL_Forwarding_GTP_Tunnel_Endpoint{"dummy"};
    QString UL_Forwarding_GTP_Tunnel_Endpoint{"dummy"};
    QString Requested_MCG_E_RAB_Level_QoS_Parameters{"dummy"};
    QString UL_Configuration{"dummy"};
    QString UL_PDCP_SN_Length{"dummy"};
    QString DL_PDCP_SN_Length{"dummy"};

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["S1_DL_GTP_Tunnel_Endpoint_at_the_SgNB"] = S1_DL_GTP_Tunnel_Endpoint_at_the_SgNB;
        obj["SgNB_UL_GTP_Tunnel_Endpoint_at_PDCP"] = SgNB_UL_GTP_Tunnel_Endpoint_at_PDCP;
        obj["RLC_Mode"] = RLC_Mode;
        obj["DL_Forwarding_GTP_Tunnel_Endpoint"] = DL_Forwarding_GTP_Tunnel_Endpoint;
        obj["UL_Forwarding_GTP_Tunnel_Endpoint"] = UL_Forwarding_GTP_Tunnel_Endpoint;
        obj["Requested_MCG_E_RAB_Level_QoS_Parameters"] = Requested_MCG_E_RAB_Level_QoS_Parameters;
        obj["UL_Configuration"] = UL_Configuration;
        obj["UL_PDCP_SN_Length"] = UL_PDCP_SN_Length;
        obj["DL_PDCP_SN_Length"] = DL_PDCP_SN_Length;
        return obj;
    }

};
struct E_RAB_Acknowledge {
    QString E_RAB_ID{"dummy"};
    QString EN_DC_Resource_Configuration{"dummy"};
    QString CHOICE_Resource_Configuration{"dummy"};
    PDCP_present_in_SN_Acknowledge pdcp_present_in_sn_acknowledge;
    PDCP_not_present_in_SN_Acknowledge pdcp_not_present_in_sn_acknowledge;

    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["E_RAB_ID"] = E_RAB_ID;
        obj["EN_DC_Resource_Configuration"] = EN_DC_Resource_Configuration;
        obj["CHOICE_Resource_Configuration"] = CHOICE_Resource_Configuration;
        obj["PDCP_present_in_SN_Acknowledge"] = pdcp_present_in_sn_acknowledge.toJson();
        obj["PDCP_not_present_in_SN_Acknowledge"] = pdcp_not_present_in_sn_acknowledge.toJson();

        return obj;
    }
};

struct SgNBAdditionalRequestAcknowledge {
    QString Message_Type{"dummy"};
    QString MeNB_UE_X2AP_ID{"dummy"};
    QString SgNB_UE_X2AP_ID{"dummy"};
    E_RAB_Acknowledge e_rab_acknowledge;

    QString E_RABs_Not_Admitted_List{"dummy"};
    QString SgNB_to_MeNB_Container{"dummy"};
    QString Criticality_Diagnostics{"dummy"};
    QString MeNB_UE_X2AP_ID_Extension{"dummy"};
    QString dmitted_split_SRBs{"dummy"};
    QString SgNB_Resource_Coordination_Information{"dummy"};
    QString RRC_config_indication{"dummy"};
    QString Location_Information_at_SgNB{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Message_Type"] = Message_Type;
        obj["MeNB_UE_X2AP_ID"] = MeNB_UE_X2AP_ID;
        obj["SgNB_UE_X2AP_ID"] = SgNB_UE_X2AP_ID;
        obj["E_RAB_Acknowledge"] = e_rab_acknowledge.toJson();
        obj["E_RABs_Not_Admitted_List"] = E_RABs_Not_Admitted_List;
        obj["SgNB_to_MeNB_Container"] = SgNB_to_MeNB_Container;
        obj["Criticality_Diagnostics"] = Criticality_Diagnostics;
        obj["MeNB_UE_X2AP_ID_Extension"] = MeNB_UE_X2AP_ID_Extension;
        obj["dmitted_split_SRBs"] = dmitted_split_SRBs;
        obj["SgNB_Resource_Coordination_Information"] = SgNB_Resource_Coordination_Information;
        obj["RRC_config_indication"] = RRC_config_indication;
        obj["Location_Information_at_SgNB"] = Location_Information_at_SgNB;
        return obj;
    }
};


//SgNB_Reconfiguration_Complete message
struct Configuration_successfully_applied {
    QString MeNB_to_SgNB_container{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["MeNB_to_SgNB_container"] = MeNB_to_SgNB_container;
        return obj;
    }
};
struct Configuration_rejected {
    QString cause{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["cause"] = cause;
        return obj;
    }
};
struct CHOICE_Response_Type {
    Configuration_successfully_applied configuration_successfully_applied;
    Configuration_rejected configuration_rejected;
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Configuration_successfully_applied"] = configuration_successfully_applied.toJson();
        obj["Configuration_rejected"] = configuration_rejected.toJson();
        return obj;
    }
};
struct SgNBReconfigurationComplete {
    QString Message_Type{"dummy"};
    QString MeNB_UE_X2AP_ID{"dummy"};
    QString SgNB_UE_X2AP_ID{"dummy"};
    QString Response_Information{"dummy"};
    CHOICE_Response_Type CHOICE_Response_Type;
    QString MeNB_UE_X2AP_ID_Extension{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Message_Type"] = Message_Type;
        obj["MeNB_UE_X2AP_ID"] = MeNB_UE_X2AP_ID;
        obj["SgNB_UE_X2AP_ID"] = SgNB_UE_X2AP_ID;
        obj["CHOICE_Response_Type"] = CHOICE_Response_Type.toJson();
        obj["MeNB_UE_X2AP_ID_Extension"] = MeNB_UE_X2AP_ID_Extension;
        return obj;
    }
};

struct RRCConnectionReconfiguration
{
    QString Message_Type{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Message_Type"] = Message_Type;
        return obj;
    }
};

struct RRCConnectionReconfigurationComplete
{
    QString Message_Type{"dummy"};
    QJsonObject toJson()
    {
        QJsonObject obj;
        obj["Message_Type"] = Message_Type;
        return obj;
    }
};

class Message{


public:

    static MESSAGE_TYPE getMessageType(QString json)
    {
        SgNBAdditionalRequest ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        if(ret.Message_Type == "SgNBAdditionalRequest")
            return SgNBAdditionalRequest_t;
        else if(ret.Message_Type == "SgNBAdditionalRequestAcknowledge")
            return SgNBAdditionalRequestAcknowledge_t;
        else if(ret.Message_Type == "RRCConnectionReconfiguration")
            return RRCConnectionReconfiguration_t;
        else if(ret.Message_Type == "RRCConnectionReconfigurationComplete")
            return RRCConnectionReconfigurationComplete_t;
        else if(ret.Message_Type == "SgNBReconfigurationComplete")
            return SgNBReconfigurationComplete_t;
    }

    static SgNBAdditionalRequest getSgNBAdditionalRequest(QString json)
    {
        SgNBAdditionalRequest ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        ret.MeNB_UE_X2AP_ID = jsonObject["MeNB_UE_X2AP_ID"].toString();
        ret.NR_UE_Security_Capabilities = jsonObject["NR_UE_Security_Capabilities"].toString();
        ret.SgNB_Security_Key = jsonObject["SgNB_Security_Key"].toString();
        ret.SgNB_UE_Aggregate_Maximum_Bit_Rate = jsonObject["SgNB_UE_Aggregate_Maximum_Bit_Rate"].toString();
        ret.Selected_PLMN = jsonObject["Selected_PLMN"].toString();
        ret.Handover_Restriction_List = jsonObject["Handover_Restriction_List"].toString();

        ret.e_rab_request.E_RAB_ID = jsonObject["E_RAB_Request"].toObject()["E_RAB_ID"].toString();
        ret.e_rab_request.DRB_ID = jsonObject["E_RAB_Request"].toObject()["DRB_ID"].toString();
        ret.e_rab_request.EN_DC_Resource_Configuration = jsonObject["E_RAB_Request"].toObject()["EN_DC_Resource_Configuration"].toString();
        ret.e_rab_request.CHOICE_Resource_Configuration = jsonObject["E_RAB_Request"].toObject()["CHOICE_Resource_Configuration"].toString();

        ret.e_rab_request.pdcp_present_in_sn.Full_E_RAB_Level_QoS_Parameters = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["Full_E_RAB_Level_QoS_Parameters"].toString();
        ret.e_rab_request.pdcp_present_in_sn.Maximum_MCG_admittable_E_RAB_Level_QoS_Parameters = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["Maximum_MCG_admittable_E_RAB_Level_QoS_Parameters"].toString();
        ret.e_rab_request.pdcp_present_in_sn.DL_Forwarding = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["DL_Forwarding"].toString();
        ret.e_rab_request.pdcp_present_in_sn.MeNB_DL_GTP_Tunnel_Endpoint_at_MCG = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["MeNB_DL_GTP_Tunnel_Endpoint_at_MCG"].toString();
        ret.e_rab_request.pdcp_present_in_sn.S1_UL_GTP_Tunnel_Endpoint = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["S1_UL_GTP_Tunnel_Endpoint"].toString();
        ret.e_rab_request.pdcp_present_in_sn.RLC_Mode = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["RLC_Mode"].toString();
        ret.e_rab_request.pdcp_present_in_sn.Bearer_Type = jsonObject["E_RAB_Request"].toObject()["PDCP_present_in_SN"].toObject()["Bearer_Type"].toString();

        ret.e_rab_request.pdcp_not_present_in_sn.Requested_SCG_E_RAB_Level_QoS_Parameters = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["Requested_SCG_E_RAB_Level_QoS_Parameters"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.Secondary_MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["Secondary_MeNB_UL_GTP_Tunnel_Endpoint_at_PDCP"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.RLC_Mode = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["RLC_Mode"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.UL_Configuration = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["UL_Configuration"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.UL_PDCP_SN_Length = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["UL_PDCP_SN_Length"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.DL_PDCP_SN_Length = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["DL_PDCP_SN_Length"].toString();
        ret.e_rab_request.pdcp_not_present_in_sn.Duplication_activation = jsonObject["E_RAB_Request"].toObject()["PDCP_not_present_in_SN"].toObject()["Duplication_activation"].toString();

        ret.MeNB_to_SgNB_Container = jsonObject["MeNB_to_SgNB_Container"].toString();
        ret.SgNB_UE_X2AP_ID = jsonObject["SgNB_UE_X2AP_ID"].toString();
        ret.Expected_UE_Behaviour = jsonObject["Expected_UE_Behaviour"].toString();
        ret.MeNB_UEU_X2AP_ID_Extension = jsonObject["MeNB_UEU_X2AP_ID_Extension"].toString();
        ret.Requested_split_SRBs = jsonObject["Requested_split_SRBs"].toString();
        ret.MeNB_Resource_Coordination_Information = jsonObject["MeNB_Resource_Coordination_Information"].toString();
        ret.SGNB_Addition_Trigger_Indication = jsonObject["SGNB_Addition_Trigger_Indication"].toString();
        ret.Subscriber_Profile_ID_for_RAT_Frequency_priority = jsonObject["Subscriber_Profile_ID_for_RAT_Frequency_priority"].toString();
        ret.MeNB_Cell_ID = jsonObject["MeNB_Cell_ID"].toString();
        ret.Desired_Activity_Notification_Level = jsonObject["Desired_Activity_Notification_Level"].toString();
        ret.Trace_Activation = jsonObject["Trace_Activation"].toString();
        ret.Location_Information_at_SgNB_reporting = jsonObject["Location_Information_at_SgNB_reporting"].toString();
        ret.Masked_IMEISV = jsonObject["Masked_IMEISV"].toString();

        return ret;

    }

    static SgNBAdditionalRequestAcknowledge getSgNBAdditionalRequestAcknowledge(QString json)
    {
        SgNBAdditionalRequestAcknowledge ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        ret.MeNB_UE_X2AP_ID= jsonObject["MeNB_UE_X2AP_ID"].toString();
        ret.SgNB_UE_X2AP_ID= jsonObject["SgNB_UE_X2AP_ID"].toString();

        ret.e_rab_acknowledge.E_RAB_ID = jsonObject["E_RAB_ID"].toObject()["E_RAB_ID"].toString();
        ret.e_rab_acknowledge.EN_DC_Resource_Configuration = jsonObject["E_RAB_ID"].toObject()["EN_DC_Resource_Configuration"].toString();
        ret.e_rab_acknowledge.CHOICE_Resource_Configuration = jsonObject["E_RAB_ID"].toObject()["CHOICE_Resource_Configuration"].toString();

        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.S1_DL_GTP_Tunnel_Endpoint_at_the_SgNB = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["S1_DL_GTP_Tunnel_Endpoint_at_the_SgNB"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.SgNB_UL_GTP_Tunnel_Endpoint_at_PDCP = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["SgNB_UL_GTP_Tunnel_Endpoint_at_PDCP"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.RLC_Mode = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["RLC_Mode"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.DL_Forwarding_GTP_Tunnel_Endpoint = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["DL_Forwarding_GTP_Tunnel_Endpoint"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.UL_Forwarding_GTP_Tunnel_Endpoint = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["UL_Forwarding_GTP_Tunnel_Endpoint"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.Requested_MCG_E_RAB_Level_QoS_Parameters = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["Requested_MCG_E_RAB_Level_QoS_Parameters"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.UL_Configuration = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["UL_Configuration"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.UL_PDCP_SN_Length = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["UL_PDCP_SN_Length"].toString();
        ret.e_rab_acknowledge.pdcp_present_in_sn_acknowledge.DL_PDCP_SN_Length = jsonObject["E_RAB_ID"].toObject()["PDCP_present_in_SN_Acknowledge"].toObject()["DL_PDCP_SN_Length"].toString();

        ret.e_rab_acknowledge.pdcp_not_present_in_sn_acknowledge.SgNB_DL_GTP_Tunnel_Endpoint_at_SCG = jsonObject["E_RAB_ID"].toObject()["PDCP_not_present_in_SN_Acknowledge"].toObject()["SgNB_DL_GTP_Tunnel_Endpoint_at_SCG"].toString();
        ret.e_rab_acknowledge.pdcp_not_present_in_sn_acknowledge.Secondary_SgNB_DL_GTP_Tunnel_Endpoint_at_SCG = jsonObject["E_RAB_ID"].toObject()["PDCP_not_present_in_SN_Acknowledge"].toObject()["Secondary_SgNB_DL_GTP_Tunnel_Endpoint_at_SCG"].toString();
        ret.e_rab_acknowledge.pdcp_not_present_in_sn_acknowledge.LCID = jsonObject["E_RAB_ID"].toObject()["PDCP_not_present_in_SN_Acknowledge"].toObject()["LCID"].toString();

        ret.E_RABs_Not_Admitted_List = jsonObject["E_RABs_Not_Admitted_List"].toString();
        ret.SgNB_to_MeNB_Container = jsonObject["SgNB_to_MeNB_Container"].toString();
        ret.Criticality_Diagnostics = jsonObject["Criticality_Diagnostics"].toString();
        ret.MeNB_UE_X2AP_ID_Extension = jsonObject["MeNB_UE_X2AP_ID_Extension"].toString();
        ret.dmitted_split_SRBs = jsonObject["dmitted_split_SRBs"].toString();
        ret.SgNB_Resource_Coordination_Information = jsonObject["SgNB_Resource_Coordination_Information"].toString();
        ret.RRC_config_indication = jsonObject["RRC_config_indication"].toString();
        ret.Location_Information_at_SgNB = jsonObject["Location_Information_at_SgNB"].toString();


        return ret;
    }

    static SgNBReconfigurationComplete getSgNBReconfigurationComplete(QString json)
    {
        SgNBReconfigurationComplete ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        ret.SgNB_UE_X2AP_ID = jsonObject["SgNB_UE_X2AP_ID"].toString();
        ret.Response_Information = jsonObject["Response_Information"].toString();

        ret.CHOICE_Response_Type.configuration_successfully_applied.MeNB_to_SgNB_container = jsonObject["CHOICE_Response_Type"].toObject()["Configuration_successfully_applied"].toObject()["MeNB_to_SgNB_container"].toString();
        ret.CHOICE_Response_Type.configuration_rejected.cause = jsonObject["CHOICE_Response_Type"].toObject()["Configuration_rejected"].toObject()["cause"].toString();

        ret.MeNB_UE_X2AP_ID_Extension = jsonObject["MeNB_UE_X2AP_ID_Extension"].toString();
        return ret;
    }

    static RRCConnectionReconfiguration getRRCConnectionReconfiguration(QString json)
    {
        RRCConnectionReconfiguration ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        return ret;
    }

    static RRCConnectionReconfigurationComplete getRRCConnectionReconfigurationCompletee(QString json)
    {
        RRCConnectionReconfigurationComplete ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        ret.Message_Type = jsonObject["Message_Type"].toString();
        return ret;
    }


};
#endif // MESSAGE_HPP

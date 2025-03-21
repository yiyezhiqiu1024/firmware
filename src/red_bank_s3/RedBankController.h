#pragma once

#include <vector>
#include "mesh/generated/meshtastic/mesh.pb.h"

namespace RedBankS3 {
    class RedBankController {

    public:
        RedBankController();
        ~RedBankController();
        void setup();
        void loop();
        
        bool isMeshPacketListEmpty();
        void saveMeshPacket(const meshtastic_MeshPacket &mp);
        meshtastic_MeshPacket getCurrentMeshPacket();

    private:
        // 消息列表容量
        static const int MESH_PACKET_LIST_CAPCITY = 10;
        // 消息列表 
        std::vector<meshtastic_MeshPacket> *m_meshPacketList; 
        // 当前消息索引
        int m_currentMeshPacketIndex;

        int _getMeshPacketListSize();
        void _previousMeshPacket();
        void _nextMeshPacket();
        void _handlePreMeshPacketButtonPress();  
        void _handleNextMeshPacketButtonPress(); 
        void _handleShuttingDownButtonPress();
        
    };
}
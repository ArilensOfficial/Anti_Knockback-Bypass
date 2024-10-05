#include <iostream>
#include <string>

// Anti knockback bypass için değişken
bool AntiKnockBackToggle = true;

// Knockback uygulayan fonksiyon
class Entity {
public:
    float velocity = 0;

    void ApplyKnockback(float knockbackForce) {
        if (AntiKnockBackToggle) {
            // Knockback kuvvetini %20'ye düşür (veya tamamen kaldırmak için 0 yapabilirsin)
            knockbackForce *= 0.2f;
        }

        velocity += knockbackForce;
        std::cout << "Knockback applied. Current velocity: " << velocity << std::endl;
    }
};

// Path üzerinden AntiKnockBackToggle kontrolü
bool GetAntiKnockBackStateFromPath(const std::string& path) {
    if (path == "AntiKnockBackToggle") {
        return true;
    } else {
        return false;
    }
}

// Sunucu ismini kontrol eden fonksiyon (örnek)
std::string GetCurrentServerName() {
    // Gerçek sunucu adını döndüren fonksiyon burada kullanılmalı
    // Şu anda örnek sunucu isimlerini döndürüyor
    return "play.hivemc.com";  // Test için bir sunucu ismi döndürülüyor.
}

// Sunucu kontrol fonksiyonu
void CheckServerAndEnableBypass(const std::string& currentServer) {
    // Belirlenen sunuculardan birindeysek knockback bypass aktif olur
    if (currentServer == "play.hivemc.com" || 
        currentServer == "cubecraft.net" || 
        currentServer == "play.nethergames.org") {
        AntiKnockBackToggle = true;
        std::cout << "AntiKnockBack bypass enabled on: " << currentServer << std::endl;
    } else {
        AntiKnockBackToggle = false;
        std::cout << "AntiKnockBack bypass disabled on: " << currentServer << std::endl;
    }
}

// Test amaçlı main fonksiyonu
int main() {
    Entity player;
    
    // Knockback kuvveti (örneğin, 10)
    float knockbackForce = 10.0f;

    // Path üzerinden AntiKnockBackToggle durumu kontrol edilir
    std::string path = "AntiKnockBackToggle";
    AntiKnockBackToggle = GetAntiKnockBackStateFromPath(path);

    // Sunucu kontrolü ve bypass etkinleştirme
    std::string currentServer = GetCurrentServerName();
    CheckServerAndEnableBypass(currentServer);

    // Knockback uygula
    player.ApplyKnockback(knockbackForce);

    // Başka bir durumda Toggle'ı kapatabiliriz
    AntiKnockBackToggle = false;
    player.ApplyKnockback(knockbackForce);

    return 0;
}
#include "ModelManager.h"

namespace JoeBidenWakeup
{
    std::shared_ptr<Model> ModelManager::get(const std::string& filename)
    {
        if (models.find(filename) == models.end())
        {
            std::shared_ptr model = std::make_shared<Model>();
            model->load(filename);
            models[filename] = model;
        }
        return models[filename];
    }

    ModelManager gModelManager;
}
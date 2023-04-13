/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <ignition/math/Vector3.hh>

#include <gazebo/physics/Actor.hh>
#include <gazebo/physics/CylinderShape.hh>
#include <gazebo/physics/BoxShape.hh>
#include "gazebo/physics/Shape.hh"
#include <gazebo/physics/Collision.hh>
#include <gazebo/physics/Link.hh>
#include "ActorCollisionsPlugin.hh"

#include <typeinfo>

using namespace gazebo;
GZ_REGISTER_MODEL_PLUGIN(ActorCollisionsPlugin)


/////////////////////////////////////////////////
ActorCollisionsPlugin::ActorCollisionsPlugin()
{
}

/////////////////////////////////////////////////
void ActorCollisionsPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
  std::cout << "Loading ActorCollisionsPlugin" << std::endl;
  std::cout << "Model name: " << _model->GetName() << std::endl;
  // Get a pointer to the actor
  auto actor = boost::dynamic_pointer_cast<physics::Actor>(_model);

  // Map of collision scaling factors
  std::map<std::string, ignition::math::Vector3d> scaling;
  std::map<std::string, ignition::math::Pose3d> offsets;

  // Read in the collision scaling factors, if present
  if (_sdf->HasElement("scaling"))
  {
    auto elem = _sdf->GetElement("scaling");
    while (elem)
    {
      if (!elem->HasAttribute("collision"))
      {
        gzwarn << "Skipping element without collision attribute" << std::endl;
        elem = elem->GetNextElement("scaling");
        continue;
      }
      auto name = elem->Get<std::string>("collision");

      if (elem->HasAttribute("scale"))
      {
        auto scale = elem->Get<ignition::math::Vector3d>("scale");
        scaling[name] = scale;
      }

      if (elem->HasAttribute("pose"))
      {
        auto pose = elem->Get<ignition::math::Pose3d>("pose");
        offsets[name] = pose;
      }
      elem = elem->GetNextElement("scaling");
    }
  }

  for (const auto &link : actor->GetLinks())
  {
    // Init the links, which in turn enables collisions
    link->Init();
    std::cout << "_________________________" << std::endl;
    std::cout << typeid(link).name() << std::endl;

    if (scaling.empty())
      continue;

    // Process all the collisions in all the links
    for (const auto &collision : link->GetCollisions())
    {
      auto name = collision->GetName();

      auto old_shape = collision->GetShape();
      std::cout << "___________old_shape______________" << std::endl;
      std::cout << typeid(old_shape).name() << std::endl;

      auto parent = collision->GetShape()->GetParent();
      std::cout << "___________parent______________" << std::endl;
      std::cout << typeid(parent).name() << std::endl;

      gazebo::physics::CylinderShapePtr cylinder_shape(new gazebo::physics::CylinderShape(collision));
      cylinder_shape->SetSize(0.5, 1.0);
      // auto shape = boost::dynamic_pointer_cast<gazebo::physics::CylinderShape>(collision->GetShape()->GetParent());
      std::cout << "New shape type: " << cylinder_shape->GetType() << std::endl;
      if(cylinder_shape){

        std::cout << collision->GetShape()->GetParent() << std::endl;
        std::cout << cylinder_shape << std::endl;

        collision->SetShape(cylinder_shape);

        auto new_shape = collision->GetShape();
        std::cout << "___________new_shape______________" << std::endl;
        std::cout << typeid(new_shape).name() << std::endl;

      }
      //TODO collision legyen cylinder

      /*if (scaling.find(name) != scaling.end())
      {
        auto boxShape = boost::dynamic_pointer_cast<gazebo::physics::BoxShape>(
            collision->GetShape());

        // Make sure we have a box shape.
        if (boxShape)
          boxShape->SetSize(boxShape->Size() * scaling[name]);

        auto cylinderShape = boost::dynamic_pointer_cast<gazebo::physics::CylinderShape>(
            collision->GetShape());

        if (cylinderShape)
          cylinderShape->SetScale(scaling[name]);
      }

      if (offsets.find(name) != offsets.end())
      {
        collision->SetInitialRelativePose(
            offsets[name] + collision->InitialRelativePose());
      }*/
    }
  }
}
